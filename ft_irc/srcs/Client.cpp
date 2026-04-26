#include "Client.hpp"


// Constructor principal
Client::Client(int fd)
: _fd(fd),
_inbuf(),
_outbuf(),
_passAccepted(false),
_registered(false),
_nick("defa_nick"),   // inicialización con valor por defecto 9 caracteres
_hasNick(false),
_user("def_user"),   // inicialización con valor por defecto 8 caracteres
_hasUser(false),
_host(),       // inicialización con valor por defecto
_umode(),
_realName("Unknown")
{
    std::cout << "Client created with fd=" << fd << std::endl;
}

// Copia (clona estado, NO duplica descriptor porque FD lo maneja RAII)
Client::Client(const Client& other) 
: _fd(-1),
_inbuf(other._inbuf),
_outbuf(other._outbuf),
_passAccepted(other._passAccepted),
_registered(other._registered),
_nick(other._nick),
_hasNick(other._hasNick),
_user(other._user),
_hasUser(other._hasUser),
_host(other._host),
_umode(other._umode),
_realName(other._realName)
{
    std::cerr << "Warning: Client copy constructed, fd not duplicated\n";
}

// Operador asignación
Client& Client::operator=(const Client& other) {
    if (this != &other) {
        _inbuf = other._inbuf;
        _outbuf = other._outbuf;
        _passAccepted = other._passAccepted;
        _registered = other._registered;
        _nick = other._nick;
        _hasNick = other._hasNick;
        _user = other._user;
        _hasUser = other._hasUser;
        _host = other._host;
        _umode = other._umode;
        _realName = other._realName;
        // fd no se copia porque no tiene sentido duplicar el socket
    }
    return *this;
}

// Destructor
Client::~Client() {
    std::cout << "Client destroyed fd=" << _fd.get() << std::endl;
}

// Métodos de acceso
int Client::getFd() const { return _fd.get(); }
std::string& Client::getInBuffer() { return _inbuf; }
std::string& Client::getOutBuffer() { return _outbuf; }

// Métodos de comprobación (password y registro)
void Client::setPassAccepted(bool ok) { _passAccepted = ok; }
bool Client::isPassAccepted() const { return _passAccepted; }

void Client::setRegistered(bool ok) { _registered = ok; }
bool Client::isRegistered() const { return _registered; }

// Métodos NICK / USER
void Client::setNick(const std::string& nick) { 
    _nick = NickName(nick); _hasNick = true;
    _hasNick = true;
}
void Client::setUser(const std::string& user) { 
    _user = UserName(user); _hasUser = true;
    _hasUser = true; 
}

std::string Client::getNick() const { return _hasNick ? _nick.get() : ""; }
std::string Client::getUser() const { return _hasUser ? _user.get() : ""; }

bool Client::hasNick() const { return _hasNick; }
bool Client::hasUser() const { return _hasUser; }

// Métodos HOST
void Client::setHost(const std::string& host) { _host = HostName(host); }
std::string Client::getHost() const { return _host.get(); }
bool Client::hasHost() const { return !_host.get().empty(); }

// Getters por objeto
NickName& Client::getNickObj() { return _nick; }
const NickName& Client::getNickObj() const { return _nick; }

UserName& Client::getUserObj() { return _user; }
const UserName& Client::getUserObj() const { return _user; }

HostName& Client::getHostObj() { return _host; }
const HostName& Client::getHostObj() const { return _host; }

// Nuevo método para mensajes
void Client::enqueueIrcMessage(const std::string& msg) {
    _outbuf += msg + "\r\n"; // IRC messages terminan en CRLF
}

// Métodos MODE
const std::string & Client::getUsermode() {
    return this->_umode;
}

void Client::setUsermode(std::string & u_mode){
    this->_umode=u_mode;
    return ;
}
// M'etodos RealName
void Client::setRealName(const std::string& realname) { 
    this->_realName=realname;
    return ;
}

std::string Client::getRealName() const { return this->_realName ;}
