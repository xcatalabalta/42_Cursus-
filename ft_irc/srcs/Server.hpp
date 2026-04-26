#ifndef SERVER_HPP
#define SERVER_HPP

#include "FileDescriptor.hpp"
#include "Client.hpp"
#include "Parser.class.hpp"
#include <sys/socket.h>    
#include <list>
#include <vector>
#include <map>
#include <poll.h>
#include <string>

class Channel;
class Parser;

class Server { 

public:
    Server(int port, const std::string& password);
    ~Server();
    void run();

    /*Metodos para el registro y seguimiento del cliente*/
    const std::string& getPassword() const;
    void tryRegister(Client& client);
    void debugPrintClients() const;
    Client* findNick(const NickName& nick) const;
    
    // Envía un NOTICE global a todos los clientes registrados,
    // excepto opcionalmente a 'exclude' si no es NULL.
    void broadcastNotice(const std::string &text,
                         const Client *exclude = NULL);
    
    /*Metodos para el creacion, control y seguimiento de canales*/
    Channel* findChannel(const std::string& name);
    Channel& createChannel(const std::string& name);
    void debugChannels() const;
    void listAllChannels(Client &client);
    void listChannels(Client * client) const;
    void leaveAllChannels(Client &client, const std::string &quitMessage = "Client disconnected");
    void purgeChannels();
    void sendMessageToChannel(Client* sender, 
            const std::string& channelName, 
            const std::string& message);
    void listSingleChannel(const std::string& channelName, Client* requester) const;
    void sendPrivateMessage(Client* sender,
            const std::string& targetNick,
            const std::string& text);


private:

    int                             _port;
    std::string                     _password;
    std::string                     _serverName;
    FileDescriptor                  _listen;     // socket de escucha
    std::list<Client*>              _clients;
    std::vector<pollfd>             _pollfds;    // se reconstruye en cada loop
	Parser*					        _parser;     // Parser con acceso al server.
    static IrcMM                    _ircMM;
    std::map<std::string, Channel*> _channels; //Aqui guardaremos los canales clave = nombre del canal

    void setupListenSocket();
    void rebuildPollFds();
    void acceptLoop();                   // aceptar hasta EAGAIN
    //std::string getClientIP(const sockaddr_in& cli, socklen_t len) const;
    void handleClientReadable(int cfd);  // leer hasta EAGAIN; parseo IRC a futuro
    void handleClientWritable(int cfd);  // enviar outbuf hasta EAGAIN
    std::list<Client*>::iterator findClient(int cfd);
    void dropClient(std::list<Client*>::iterator it);
    static void ignoreSigpipeOnce();     // evitar SIGPIPE global
    void broadcastMessage(int sender_fd, const std::string &message); //Envia mensaje replica a todos los clientes
    
    
};

#endif
