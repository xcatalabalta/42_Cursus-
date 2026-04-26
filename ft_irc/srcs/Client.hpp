#ifndef CLIENT_HPP
#define CLIENT_HPP

#include "FileDescriptor.hpp"
#include "NickName.class.hpp"
#include "UserName.class.hpp"
#include "HostName.class.hpp"
#include <string>
#include <iostream>

class Client {
public:
    // Canonical form
    Client(int fd);
    //Client(int fd, const std::string& host);
    Client(const Client& other);
    Client& operator=(const Client& other);
    ~Client();

    // Metodos básicos
    int getFd() const;
    std::string& getInBuffer();
    std::string& getOutBuffer();

    //Metodos de comprobacion
    void setPassAccepted(bool ok);
    bool isPassAccepted() const;
    void setRegistered(bool ok);
    bool isRegistered() const;

    // Métodos NICK / USER
    void setNick(const std::string& nick);
    void setUser(const std::string& user);
    std::string getNick() const;
    std::string getUser() const;

    bool hasNick() const;
    bool hasUser() const;

    // Métodos HOST
    void setHost(const std::string& host);
    std::string getHost() const;
    bool hasHost() const;
    
    //Getters por objeto (para integración con IrcMM) 
    NickName& getNickObj();
    const NickName& getNickObj() const;
    UserName& getUserObj();
    const UserName& getUserObj() const;
    HostName& getHostObj();
    const HostName& getHostObj() const;
    // Métodos del MODE
    void setUsermode(std::string & u_mode);
    const std::string & getUsermode();

    //metodos del RealName
    std::string getRealName() const;
    void setRealName(const std::string& realname);    
    

    // Agregado: Encolar mensaje formateado para IRC
    void enqueueIrcMessage(const std::string& msg);


private:
    FileDescriptor _fd;   // socket del cliente (RAII)
    std::string    _inbuf;
    std::string    _outbuf;

    bool           _passAccepted;  // true si PASS correcto
    bool           _registered;    // true si PASS+NICK+USER completos


    NickName       _nick;
    bool           _hasNick;

    UserName       _user;
    bool           _hasUser;

    HostName       _host;
    
    //std::list<Channel*> _channels;  // para evitar duplicados
    std::string _umode ;
    std::string _realName ; 

};

#endif