#include "Server.hpp"
#include "IrcMM.class.hpp"
#include "Parser.class.hpp"
#include "Channel.class.hpp"
#include <stdexcept>
#include <iostream>
#include <cstring>
#include <cerrno>
#include <csignal>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstdio>
#include <sstream>
#include <netdb.h> 

IrcMM Server::_ircMM =  IrcMM();

/// @brief Constructor del servidor IRC
/// @param port Puerto de escucha (1-65535)
/// @param password Contraseña del servidor (no puede estar vacía)
/// @throw std::invalid_argument Si port o password son inválidos
/// @throw std::runtime_error Si falla la configuración del socket
Server::Server(int port, const std::string& password)
:   _port(port),
    _password(password),
    _serverName("ircserver"),
    _listen(),
    _parser(NULL) {
        std::cout << "Server constructor start\n";
        // Validaciones
        if (port < 1 || port > 65535)
            throw std::invalid_argument("Port must be between 1 and 65535");
        if (password.empty())
            throw std::invalid_argument("Password cannot be empty");
        ignoreSigpipeOnce();
        setupListenSocket();
        _parser = new Parser(*this); // parser recibe referencia al server
}

/// @brief Destructor - Libera todos los recursos del servidor
Server::~Server() {
    // liberar todos los clientes
    for (std::list<Client*>::iterator it = _clients.begin(); it != _clients.end(); ++it) {
        delete *it;
    }
    _clients.clear(); //teoricamente no es necesario, se destruye automaticamente.
    
    //Liberar parser
    delete _parser;
    
    //liberar canales
    for (std::map<std::string, Channel*>::iterator it = _channels.begin();
         it != _channels.end(); ++it)
    {
        delete it->second;
    }
}

/// @brief Ignora SIGPIPE globalmente (solo se ejecuta una vez)
/// @note Evita que el servidor termine si un cliente cierra la conexión
///       durante send/write. Permitido explícitamente por el subject.
void Server::ignoreSigpipeOnce() {
    static bool done = false;
    if (done) return;
    struct sigaction sa;
    std::memset(&sa, 0, sizeof(sa));
    sa.sa_handler = SIG_IGN;
    //sigaction(SIGPIPE, &sa, 0); // permitido en el sujeto
    if (sigaction(SIGPIPE, &sa, NULL) < 0) {
        std::cerr << "Warning: sigaction(SIGPIPE) failed: " 
                  << strerror(errno) << "\n";
    }
    done = true;
}

/// @brief Configura y vincula el socket de escucha del servidor
/// @throw std::runtime_error Si falla la creación, configuración o bind
void Server::setupListenSocket() {
    // Crear socket TCP
    int fd = ::socket(AF_INET, SOCK_STREAM, 0);
    //std::cout << "socket() returned fd=" << fd << "\n";
    if (fd < 0) {
        std::ostringstream oss;
        oss << "socket() failed: " << strerror(errno);
        throw std::runtime_error(oss.str());
    }

    // Adoptamos con RAII: esto lo hace non-blocking automáticamente.
    _listen.reset(fd);

    // Configurar SO_REUSEADDR para evitar "Address already in use"
    int yes = 1;
    if (::setsockopt(_listen.get(), SOL_SOCKET, SO_REUSEADDR, 
                     &yes, sizeof(yes)) < 0) {
        // No crítico, pero registramos el warning
        std::cerr << "Warning: setsockopt(SO_REUSEADDR) failed: " 
                  << strerror(errno) << "\n";
    }
    //::setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes));

    // Preparar dirección de bind
    sockaddr_in addr;
    std::memset(&addr, 0, sizeof(addr));
    addr.sin_family      = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port        = htons(_port);

    // Vincular socket al puerto
    if (::bind(_listen.get(), (struct sockaddr*)&addr, sizeof(addr)) < 0){
        std::ostringstream oss;
        oss << "bind() failed on port " << _port << ": " << strerror(errno);
        throw std::runtime_error(oss.str());
    }
    // Poner socket en modo escucha
    if (::listen(_listen.get(), SOMAXCONN) < 0){
        std::ostringstream oss;
        oss << "listen() failed: " << strerror(errno);
        throw std::runtime_error(oss.str());
    }
}

/// @brief Reconstruye el array de poll con eventos actualizados
/// @details Siempre monitoreamos POLLIN para todos los sockets.
///          POLLOUT solo se añade si el cliente tiene datos pendientes.
void Server::rebuildPollFds() {
    _pollfds.clear();

    // index 0: socket de escucha (siempre solo POLLIN)
    pollfd listen_pfd = { _listen.get(), POLLIN, 0 };
    _pollfds.push_back(listen_pfd);

    // Índices 1+: clientes conectados
    for (std::list<Client*>::iterator it = _clients.begin(); it != _clients.end(); ++it) {
        pollfd c;
        c.fd = (*it)->getFd();
        c.events = POLLIN; // Siempre leer
        c.revents = 0;
        
        // Añadir POLLOUT solo si hay datos para escribir
        if (!(*it)->getOutBuffer().empty()) c.events |= POLLOUT;
            
        _pollfds.push_back(c);
    }
}

/// @brief Busca un cliente por su file descriptor
/// @param cfd File descriptor del cliente
/// @return Iterador al cliente o _clients.end() si no se encuentra
std::list<Client*>::iterator Server::findClient(int cfd) {
    for (std::list<Client*>::iterator it = _clients.begin(); it != _clients.end(); ++it)
        if ((*it)->getFd() == cfd) return it;
    return _clients.end();
}

/// @brief Desconecta y elimina un cliente del servidor
/// @param it Iterador al cliente en la lista _clients
/// @note También elimina al cliente de todos los canales
void Server::dropClient(std::list<Client*>::iterator it) {
    int fd = (*it)->getFd();
    std::string nick = (*it)->getNick();
    
    // Log de desconexión
    std::cout << "Dropping client fd=" << fd;
    if (!nick.empty())
        std::cout << " (" << nick << ")";
    std::cout << "\n";
    
    // Eliminar de todos los canales y notificar QUIT a otros usuarios
    //leaveAllChannels(**it);
    leaveAllChannels(**it, "Connection lost");
    
    // Liberar memoria (RAII cierra el fd automáticamente)
    delete *it;
    _clients.erase(it);
}

/// @brief Extrae la IP del cliente de forma segura
/// @param cli Estructura sockaddr_in del cliente
/// @param len Tamaño de la estructura
/// @return IP en formato string o "unknown" si falla
static std::string getClientIP(const sockaddr_in& cli, socklen_t len) {
    // Método 1: getnameinfo (más robusto, soporta IPv6 futuro)
    char host[NI_MAXHOST];
    if (getnameinfo(reinterpret_cast<const sockaddr*>(&cli),
                    len,
                    host,
                    sizeof(host),
                    NULL,
                    0,
                    NI_NUMERICHOST) == 0) {
        return std::string(host);
    }

    // Método 2 (fallback): inet_ntop (thread-safe)
    char ipbuf[INET_ADDRSTRLEN];
    if (inet_ntop(AF_INET, &cli.sin_addr, ipbuf, sizeof(ipbuf))) {
        return std::string(ipbuf);
    }

    // Si todo falla
    return "unknown";
}

/// @brief Acepta nuevas conexiones en bucle hasta EAGAIN/EWOULDBLOCK
/// @note Se ejecuta en modo non-blocking, acepta múltiples conexiones seguidas
void Server::acceptLoop() {
    while (true) {
        sockaddr_in cli;
        socklen_t len = sizeof(cli);

        //int cfd = ::accept(_listen.get(), (struct sockaddr*)&cli, &len);
        int cfd = ::accept(_listen.get(), 
                           reinterpret_cast<struct sockaddr*>(&cli), 
                           &len);
        if (cfd < 0) {
            // No hay más conexiones pendientes
            if (errno == EAGAIN || errno == EWOULDBLOCK) break;
            // Interrumpido por señal, reintentar
            if (errno == EINTR) continue;
            // Error real
            std::cerr << "accept() error: " << strerror(errno) << "\n";
            break;
        }

        // Obtener IP del cliente
        std::string ip = getClientIP(cli, len);

        // Crear nuevo cliente (Client debe adoptar cfd con RAII)
        Client* newClient = new Client(cfd);
        newClient->setHost(ip); 
        _clients.push_back(newClient);

        std::cout << "Accepted client fd=" << cfd 
                  << " from " << ip << "\n";
    }
}

/// @brief Maneja datos legibles de un cliente (lectura non-blocking)
/// @param cfd File descriptor del cliente
/// @note Lee hasta EAGAIN y procesa líneas IRC completas
void Server::handleClientReadable(int cfd) {
    std::list<Client*>::iterator it = findClient(cfd);
    if (it == _clients.end()) return;

    char buf[4096];
    while (true) {
        ssize_t n = ::recv(cfd, buf, sizeof(buf), 0);
        if (n > 0) {
            // Acumula datos en el buffer del cliente
            (*it)->getInBuffer().append(buf, buf + n);
            
            // Procesa cada línea completa terminada en '\n'
            std::string::size_type pos;
            while ((pos = (*it)->getInBuffer().find('\n')) != std::string::npos) {
                std::string line = (*it)->getInBuffer().substr(0, pos + 1);
                (*it)->getInBuffer().erase(0, pos + 1);
				
                // Eliminar \r al final si existe (IRC usa \r\n)
                if (!line.empty() && line[line.size() - 1] == '\r')
                    line.erase(line.size() - 1);
                
                // Ignorar líneas vacías
                if (line.empty())
                    continue;

                // Parsear comando IRC
                try {
                    _parser->parse(*it, line);
                } catch (const std::exception &e) {
                    (*it)->enqueueIrcMessage(_ircMM.Fmt_ERR_UNKNOWNCOMMAND(line));
                    std::cerr << "[WARN] Parse error: " << e.what() << "\n";
                    continue;
                }

            }
        } else if (n == 0) {
            // Cliente cerró la conexión ordenadamente
            dropClient(it);
            return;
        } else {
            // n < 0: error en recv
            if (errno == EAGAIN || errno == EWOULDBLOCK) 
                break; // No hay más datos disponibles ahora
            if (errno == EINTR) 
                continue; // Interrumpido por señal, reintentar
            
            // Error crítico (ECONNRESET, EPIPE, etc.)
            std::cerr << "recv() error on fd " << cfd 
                      << ": " << strerror(errno) << "\n";
            dropClient(it);
            return;
        }
    }
}

/// @brief Maneja escritura a un cliente (escritura non-blocking)
/// @param cfd File descriptor del cliente
/// @note Escribe hasta que el buffer esté vacío o EAGAIN
void Server::handleClientWritable(int cfd) {
    std::list<Client*>::iterator it = findClient(cfd);
    if (it == _clients.end()) return;

    while (!(*it)->getOutBuffer().empty()) {
        ssize_t n = ::send(cfd, (*it)->getOutBuffer().data(),
                           (*it)->getOutBuffer().size(), 0);
        if (n > 0) {
            // Eliminar los bytes enviados del buffer
            (*it)->getOutBuffer().erase(0, static_cast<std::string::size_type>(n));
        } else if (n < 0) {
            if (errno == EAGAIN || errno == EWOULDBLOCK) 
                break; // Buffer del SO lleno, POLLOUT nos notificará
            if (errno == EINTR) 
                continue;// Interrumpido por señal, reintentar
            // Error crítico (ECONNRESET, EPIPE, etc.)
            std::cerr << "send() error on fd " << cfd 
                      << ": " << strerror(errno) << "\n";
            dropClient(it);
            return;
        }
        // Nota: send() nunca retorna 0 con size > 0
    }
}

/// @brief Bucle principal del servidor - maneja eventos de I/O con poll()
/// @note Bucle infinito - solo termina con señales o excepciones
/// @throw std::runtime_error Si poll() falla irrecuperablemente
void Server::run() {
    std::cout << "Listening on port " << _port << " …\n";
    for (;;) {
        // Reconstruir array de poll con eventos actualizados
        rebuildPollFds();
        
        // Esperar eventos (timeout infinito)
        int ready = ::poll(&_pollfds[0], _pollfds.size(), -1);
        if (ready < 0) {
            if (errno == EINTR) continue;// Interrumpido por señal, reintentar
            
            // Error crítico
            std::ostringstream oss;
            oss << "poll() failed: " << strerror(errno);
            throw std::runtime_error(oss.str());
            //throw std::runtime_error("poll() failed");
        }

        // Manejar conexiones nuevas en el socket de escucha (índice 0)
        //if (_pollfds[0].revents & POLLIN) {
        if (!_pollfds.empty() && (_pollfds[0].revents & POLLIN)) {
            acceptLoop();
        }

        // Manejar eventos de clientes existentes (índices 1+)
        for (size_t i = 1; i < _pollfds.size(); ++i) {
            int cfd = _pollfds[i].fd;
            short re = _pollfds[i].revents;

            if (re & (POLLERR | POLLHUP | POLLNVAL)) {
                std::list<Client*>::iterator it = findClient(cfd);
                if (it != _clients.end()) dropClient(it);
                continue;
            }
            // Manejar lectura
            if (re & POLLIN)  handleClientReadable(cfd);
                // Verificar si el cliente fue eliminado durante la lectura
                if (findClient(cfd) == _clients.end())
                    continue;
            
            // Manejar escritura (solo si el cliente aún existe)
            // Si el buffer de salida está lleno (ej: cliente suspendido con Ctrl+Z),
            // POLLOUT nos notifica cuando podemos escribir de nuevo
            if (re & POLLOUT) handleClientWritable(cfd); //si el cliente esta suspeendido ctrol+z el buffer de salida esta lleno
        }
    }
}


/// @brief Envía un mensaje a TODOS los clientes conectados
/// @warning Solo usar para mensajes globales del servidor
/// @param sender_fd FD del remitente (se excluye del broadcast)
/// @param message Mensaje a enviar (debe incluir formato IRC completo)
void Server::broadcastMessage(int sender_fd, const std::string &message) {
    for (std::list<Client*>::iterator it = _clients.begin(); it != _clients.end(); ++it) {
        // int cfd = (*it)->getFd();
        // if (cfd != sender_fd) {
        //     // añadimos a su outbuf para que lo saque handleClientWritable(Client * client)
        //     (*it)->getOutBuffer() += message;
        // }
        if ((*it)->getFd() != sender_fd) {
            (*it)->enqueueIrcMessage(message); // Mejor que acceso directo al buffer
        }

    }
}

/// @brief getter del password del server
const std::string& Server::getPassword() const {
    return _password;
}

/// @brief Intenta completar el registro del cliente
/// @param client Cliente que intenta registrarse
/// @note Requiere PASS, NICK y USER en ese orden según protocolo IRC
void Server::tryRegister(Client& client)
{
    // 1. Si ya está registrado no hacemos nada
    if (client.isRegistered())
        return;

    // 2. El protocolo IRC requiere PASS correcto *antes* de todo
    if (!client.isPassAccepted())
        return; // Aún no envió PASS válido

    // 3. Después comprobamos NICK: debe existir y no estar en uso
    if (!client.hasNick())
        return; // todavía no ha enviado NICK

    //   3.a Verificamos que no haya colisión de nick
    for (std::list<Client*>::iterator it = _clients.begin(); it != _clients.end(); ++it) {
        Client* other = *it;
        if (other != &client && other->isRegistered()
            && other->getNick() == client.getNick())
        {
            client.enqueueIrcMessage(
                _ircMM.Fmt_ERR_NICKNAMEINUSE(client.getNick()));
            return; // nick en uso, el cliente puede intentar otro
        }
    }

    // 4. Por último necesitamos USER válido
    if (!client.hasUser())
        return; // todavía no ha enviado USER

    // 5. Si el cliente no tiene host, mantenemos el capturado en accept()
    //    (ya se ha hecho en acceptLoop con setHost(ip), pero lo dejamos
    //    por si se conecta de forma local y aún no hay host definido)
    if (!client.hasHost())
        client.setHost("localhost");

    // 6. Marcamos como registrado
    client.setRegistered(true);

    //     // Anunciamos al resto de clientes ya registrados
    std::string notice = "Nuevo usuario conectado: " +
                     client.getNick() + " (" +
                     client.getUser() + "@" +
                     client.getHost() + ")";
    broadcastNotice(notice, &client);

    // 7. Mensaje de bienvenida (RPL_WELCOME)
    client.enqueueIrcMessage(
        _ircMM.Fmt_RPL_WELCOME(
            client.getNick(),
            client.getUser(),
            client.getHost()
        )
    );

    //8. (Opcional) enviar MOTD para emular servidor completo
    client.enqueueIrcMessage(_ircMM.Fmt_RPL_MOTDSTART(_serverName));
    client.enqueueIrcMessage(_ircMM.Fmt_RPL_MOTD("Bienvenido al servidor " + _serverName+ ": " + client.getNick()));
    client.enqueueIrcMessage(_ircMM.Fmt_RPL_ENDOFMOTD(client.getNick()));

    std::cout << "[INFO] Cliente fd=" << client.getFd()
              << " registrado con NICK=" << client.getNick()
              << " USER=" << client.getUser()
              << " HOST=" << client.getHost() << std::endl;

    debugPrintClients();
}

/// @brief Imprime información de todos los clientes conectados (debug)
void Server::debugPrintClients() const
{
    std::cout << "\n[DEBUG] --- Lista de clientes registrados ---\n";

    if (_clients.empty()) {
        std::cout << "[DEBUG] (ninguno)\n";
        return;
    }

    for (std::list<Client*>::const_iterator it = _clients.begin();
         it != _clients.end(); ++it)
    {
        const Client* c = *it;
        if (!c) continue;

        std::cout << "  fd=" << c->getFd();

        if (c->isRegistered()) {
            std::cout << "  NICK=" << c->getNick()
                      << "  USER=" << c->getUser()
                      << "  HOST=" << c->getHost()
                      << "  REALNAME=" << c->getRealName();
        } else {
            std::cout << "  (aún sin registrar)";
        }
        std::cout << "\n";
    }
    std::cout << "[DEBUG] --------------------------------------\n";
}

/// @brief Crea un nuevo canal o retorna el existente
/// @param name Nombre del canal (debe incluir # o &)
/// @return Referencia al canal (nuevo o existente)
Channel& Server::createChannel(const std::string& name) {
std::map<std::string, Channel*>::iterator it = _channels.find(name);
    if (it != _channels.end())
        return *(it->second);  // canal ya existe, devolvemos referencia

    // crear nuevo canal en el heap
    Channel* ch = new Channel(name);
    _channels[name] = ch;
    std::cout << "[INFO] Canal creado: " << name << std::endl;
    return *ch;
}

/// @brief Busca un canal por nombre
/// @param name Nombre del canal
/// @return Puntero al canal o NULL si no existe
Channel* Server::findChannel(const std::string& name) {
    std::map<std::string, Channel*>::iterator it = _channels.find(name);
    return (it != _channels.end()) ? it->second : NULL;
}

void Server::debugChannels() const {
    std::cout << "[DEBUG] Canales activos:\n";
    for (std::map<std::string, Channel*>::const_iterator it = _channels.begin();
         it != _channels.end(); ++it)
    {
        std::cout << "  #" << it->first
                  << " (" << it->second->getSizeChannel() << " miembros)\n";
    }
}

/// @brief Lista todos los canales del servidor (públicos)
/// @param client Cliente que solicita la lista
void Server::listAllChannels(Client &client)
{
    // Si no hay canales
    if (_channels.empty())
    {
        client.enqueueIrcMessage(_ircMM.Fmt_RPL_LISTEND (client.getNick()) );
        return;
    }

    // Recorrer cada canal
    for (std::map<std::string, Channel*>::const_iterator it = _channels.begin();
         it != _channels.end(); ++it)
    {
        Channel *ch = it->second;

        std::string topic = ch->getTopic();
        if (topic.empty())
            topic = "(sin topic)";
        client.enqueueIrcMessage(_ircMM.Fmt_RPL_LIST (
            client.getNick(),
            ch->getName(), 
            ch->getSizeChannel(),
            topic
        ));
    }

    // 323 RPL_LISTEND (fin de la lista de canales)
    client.enqueueIrcMessage(_ircMM.Fmt_RPL_LISTEND (client.getNick()) );
}

/// @brief Lista todos los canales del servidor visibles para el cliente
/// @param client Cliente que solicita la lista (puntero, puede ser NULL)
void Server::listChannels(Client * client) const {
    for (std::map<std::string, Channel*>::const_iterator it = _channels.begin();
         it != _channels.end(); ++it)
    {
        std::string topic = it->second->getTopic();
        if (topic.empty())
            topic = "(sin topic)";
        client->enqueueIrcMessage(
            _ircMM.Fmt_RPL_LIST(
                client->getNick(),
                it->second->getName(),
                it->second->getSizeChannel(),
                topic) ) ; 
    }
    client->enqueueIrcMessage(_ircMM.Fmt_RPL_LISTEND(client->getNick()) ) ; 
}

/// @brief Busca un cliente por su nickname
/// @param nick Nickname a buscar (objeto NickName)
/// @return Puntero al cliente si se encuentra y está registrado, NULL en caso contrario
/// @note Solo busca entre clientes registrados para evitar encontrar "clientes fantasma"
///       (conexiones que aún no completaron el handshake PASS/NICK/USER)
Client* Server::findNick(const NickName& nick) const
{
    // Extraer el string del nickname para comparación
    const std::string target = nick.get();

    // Recorrer todos los clientes conectados
    for (std::list<Client*>::const_iterator it = _clients.begin();
         it != _clients.end();
         ++it)
    {
        Client* c = *it;
        // Comprobamos solo clientes ya registrados, para no invitar a fantasmas
        if (c->isRegistered() && c->getNick() == target)
            return c;
    }
    return NULL; // No encontrado
}

/// @brief Elimina al cliente de todos los canales al desconectarse (envía QUIT)
/// @param client Cliente que se desconecta
/// @param partMessage Mensaje de PART (default: "Client disconnected")
void Server::leaveAllChannels(Client &client, const std::string &quitMessage)
{
    if (_channels.empty())
        return ;
    
    
   (void)quitMessage;
  
    for (std::map<std::string, Channel*>::const_iterator it = _channels.begin();
         it != _channels.end(); ++it)
    {
        Channel *ch = it->second;
        if (ch->isMember(&client))
        {
            std::string partMsg = ":" + client.getNick() + "!" + 
                                  client.getUser() + "@" + client.getHost() + 
                                  " PART " + ch->getName() + " :Leaving all channels";
            
            // Send PART to the leaving client
             client.enqueueIrcMessage(partMsg);
            
             // Broadcast PART to other channel members (before removing)
            ch->broadcastMessage(partMsg, &client);
            
             // Now remove the member
             ch->RemoveMember(&client);
        }
    }
}

/// @brief Elimina todos los canales vacíos del servidor
/// @note Usa two-pass approach para evitar invalidar iteradores
void Server::purgeChannels()
{
    std::vector<std::string> channelsToRemove;
    
    // First pass: identify empty channels
    for (std::map<std::string, Channel*>::iterator it = _channels.begin();
         it != _channels.end(); ++it)
    {
        if (it->second && it->second->getSizeChannel() == 0)
        {
            channelsToRemove.push_back(it->first);
        }
    }
    
    // Second pass: remove empty channels
    for (std::vector<std::string>::iterator it = channelsToRemove.begin();
         it != channelsToRemove.end(); ++it)
    {
        delete _channels[*it];
        _channels.erase(*it);
    }
}

/// @brief Envía un mensaje de un cliente a un canal
/// @param sender Cliente que envía el mensaje
/// @param channelName Nombre del canal destino
/// @param message Contenido del mensaje
void Server::sendMessageToChannel(Client* sender,
                                  const std::string& channelName,
                                  const std::string& message)
{
    // 1. Localizar el canal
    Channel* ch = findChannel(channelName);
    if (!ch)
    {
        // Error 403: No such channel
        sender->enqueueIrcMessage(
            _ircMM.Fmt_ERR_NOSUCHCHANNEL(channelName));
        return;
    }

    // 2. Verificar que el remitente es miembro
    if (!ch->isMember(sender))
    {
        // Error 442: You're not on that channel
        sender->enqueueIrcMessage(
            _ircMM.Fmt_ERR_NOTONCHANNEL(channelName));
        return;
    }

    // 3. Construir mensaje PRIVMSG
    //    :nick!user@host PRIVMSG #canal :texto
    std::string ircMsg =
        ":" + sender->getNick() + "!" + sender->getUser() + "@" + sender->getHost() +
        " PRIVMSG " + channelName + " :" + message;

    // 4. Enviar a todos los miembros salvo el emisor
    ch->broadcastMessage(ircMsg, sender);
}

/// @brief Lista información de un canal específico
/// @param channelName Nombre del canal a listar
/// @param requester Cliente que solicita la información
/// @note Canales invite-only se ocultan a no-miembros
void Server::listSingleChannel(const std::string& channelName,
                               Client* requester) const
{
    // Verificación de cliente válido
    if (!requester || !requester->isRegistered())
        return;
    
    // 1. ¿Existe el canal?
    std::map<std::string, Channel*>::const_iterator it = _channels.find(channelName);
    if (it == _channels.end())
    {
        requester->enqueueIrcMessage(
            _ircMM.Fmt_ERR_NOSUCHCHANNEL(channelName));
        return;
    }
    Channel* ch = it->second;

    // 2. Ocultar canales invite-only a no-miembros
    if (ch->isInviteOnly() && !ch->isMember(requester))
    {
        requester->enqueueIrcMessage(
            _ircMM.Fmt_ERR_NOTONCHANNEL(channelName));
        return;
    }

    // 3. Mensaje RPL_LIST: información básica del canal
    std::string topic = ch->getTopic();
    if (topic.empty())
            topic = "(sin topic)";
    requester->enqueueIrcMessage(
        _ircMM.Fmt_RPL_LIST(requester->getNick(),
                            ch->getName(),
                            ch->getSizeChannel(),
                            topic));
    // 4. Fin de lista
    requester->enqueueIrcMessage(
        _ircMM.Fmt_RPL_LISTEND(requester->getNick()));
}

/// @brief Envía un mensaje privado de un cliente a otro
/// @param sender Cliente que envía el mensaje (debe estar registrado)
/// @param targetNick Nickname del destinatario
/// @param text Contenido del mensaje
/// @note Si el destinatario no existe, envía ERR_NOSUCHNICK al remitente
void Server::sendPrivateMessage(Client* sender,
                                const std::string& targetNick,
                                const std::string& text)
{
    // 1. Comprobar que el remitente está registrado
    if (!sender || !sender->isRegistered())
        return;

    // 2. Buscar cliente destino
    Client* recipient = NULL;
    for (std::list<Client*>::iterator it = _clients.begin();
         it != _clients.end(); ++it)
    {
        if ((*it)->isRegistered() && (*it)->getNick() == targetNick)
        {
            recipient = *it;
            break;
        }
    }

    // 3. Si no se encuentra, avisar al remitente
    if (!recipient)
    {
        sender->enqueueIrcMessage(
            _ircMM.Fmt_ERR_NOSUCHNICK(sender->getNick()));
            //_ircMM.Fmt_ERR_NOSUCHNICK(sender->getNick(), targetNick));
        return;
    }

    // 4. Enviar al destinatario
    recipient->enqueueIrcMessage(
        _ircMM.Fmt_RPL_PRIVMSG( sender->getNick(),
                                sender->getUser(),
                                sender->getHost(),
                                targetNick, 
                                text)
    );

}


/// @brief Envía un NOTICE del servidor a todos los clientes registrados
/// @param text Contenido del mensaje
/// @param exclude Cliente a excluir del broadcast (opcional, NULL = enviar a todos)
/// @note Solo se envía a clientes registrados
void Server::broadcastNotice(const std::string &text,
                             const Client *exclude)
{
    // Construimos el mensaje completo con prefijo de servidor
    // std::string msg = ":" + _serverName + " NOTICE * :" + text;
    // Enviar a todos los clientes registrados excepto 'exclude'
    for (std::list<Client*>::iterator it = _clients.begin();
         it != _clients.end(); ++it)
    {
        Client *c = *it;
        if (c->isRegistered() && c != exclude)
        {
            std::string msg =":" + _serverName + " NOTICE " + c->getNick() + " :" + text;
            c->enqueueIrcMessage(msg);
        }
    }
}

