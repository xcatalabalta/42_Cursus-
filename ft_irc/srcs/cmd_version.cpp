#include "Parser.class.hpp"
#include <string>
#include <cstring>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/stat.h>
#include <ctime>

/*
      Command: VERSION
   Parameters: [ <target> ]

   The VERSION command is used to query the version of the server
   program.  An optional parameter <target> is used to query the version
   of the server program which a client is not directly connected to.

   Wildcards are allowed in the <target> parameter.

   Numeric Replies:

           ERR_NOSUCHSERVER                RPL_VERSION

   Examples:

   VERSION tolsun.oulu.fi          ; Command to check the version of
                                   server "tolsun.oulu.fi".
*/

const std::string  getHostIp() {
    char hostname[1024];
    hostname[1023] = '\0';
    gethostname(hostname, 1023);

    struct addrinfo hints, *result, *p;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET; // IPv4
    hints.ai_socktype = SOCK_STREAM;

    int status = getaddrinfo(hostname, NULL, &hints, &result);
    if (status != 0) {
        return "Error al obtener la IP";
    }

    std::string ip_address = "";
    for (p = result; p != NULL; p = p->ai_next) {
        char ipstr[INET_ADDRSTRLEN];
        void *addr;

        struct sockaddr_in *ipv4 = (struct sockaddr_in *)p->ai_addr;
        addr = &(ipv4->sin_addr);
        
        inet_ntop(p->ai_family, addr, ipstr, sizeof(ipstr));
        ip_address = ipstr;
        break; // Tomar la primera IP encontrada
    }

    freeaddrinfo(result);
    return ip_address;
}

const std::string  getFileCreationDate(const std::string& filePath) {
    struct stat fileInfo;
    std::string creationDate;
    std::string resultado = "";
    // Use stat() to get file metadata
    if (stat(filePath.c_str(), &fileInfo) == 0) {
        // The st_ctime field contains the last status change time (which is often
        // the creation time on many systems, but not guaranteed by POSIX).
        time_t creationTime = fileInfo.st_ctime;
        
        // Convert time_t to a formatted string
        char buffer[80];
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localtime(&creationTime));
        creationDate = buffer;
    } else {
        creationDate = "Error: Could not get file info.";
    }
    resultado = "The creation date of " + filePath + " is: " + creationDate ;
    return resultado ;
}

void Parser::_cmd_version(Client * client)
{
    const std::string   & v = getFileCreationDate ("ircserv");
    const std::string   & d= "Proyecto en marcha";
    const std::string   & h = getHostIp();
    const std::string   & c = "Creado por Natalia, Xavi y Luis" ;
    if (!client->isRegistered()) {
        client->enqueueIrcMessage(this->_mm.Fmt_ERR_NOTREGISTERED ());
        return ;
    }
    
    if  ( (this->_tokens.size() == 1) || 
          ( (this->_tokens.size() == 2) && (this->_tokens[1] == "ircserver") ) )
    {
        client->enqueueIrcMessage(this->_mm.Fmt_RPL_VERSION (v, d, h, c ) );

    } else {
        client->enqueueIrcMessage(this->_mm.Fmt_ERR_NOSUCHSERVER  (this->_tokens[1]));
    }
    return ;
}
