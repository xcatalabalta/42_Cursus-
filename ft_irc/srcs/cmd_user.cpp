#include "Parser.class.hpp"

/*
3.1.3 User message

      Command: USER
   Parameters: <user> <mode> <unused> <realname>

   The USER command is used at the beginning of connection to specify
   the username, hostname and realname of a new user.

   The <mode> parameter should be a numeric, and can be used to
   automatically set user modes when registering with the server.  This
   parameter is a bitmask, with only 2 bits having any signification: if
   the bit 2 is set, the user mode 'w' will be set and if the bit 3 is
   set, the user mode 'i' will be set.  (See Section 3.1.5 "User
   Modes").

   The <realname> may contain space characters.

   Numeric Replies:

           ERR_NEEDMOREPARAMS              ERR_ALREADYREGISTRED

   Example:

   USER guest 0 * :Ronnie Reagan   ; User registering themselves with a
                                   username of "guest" and real name
                                   "Ronnie Reagan".

   USER guest 8 * :Ronnie Reagan   ; User registering themselves with a
                                   username of "guest" and real name
                                   "Ronnie Reagan", and asking to be set
                                   invisible.
                                   
                                   */
                                  
void Parser::_cmd_user(Client * client)
{
    // std::stringstream msg;
    // std::cout << "USER detectado con estos parametros" << std::endl;
    // msg << "USER detectado con estos parametros" << std::endl;
    // for (size_t i = 1; i < this->_tokens.size(); ++i) {
    //     msg << this->_tokens[i] << std::endl;
    //     std::cout << this->_tokens[i] << std::endl;
    // }

    if (this->_tokens.size() < 5) {
        client->enqueueIrcMessage(
            this->_mm.Fmt_ERR_NEEDMOREPARAMS(this->_tokens[0]));
        return;
    }
    if (!client->hasUser()) {
        std::istringstream iss(this->_txt_line);
        try {
            UserName username(this->_tokens[1]);
            std::string modeflag = this->_tokens[2];
            std::string servername = this->_tokens[3];
            std::string realname = this->_tokens[4];
            int fd_int = client->getFd();
            std::stringstream ss;
            ss << fd_int;
            std::string fd_string = ss.str();

            // After token 4 all is realname.
            for (size_t i = 5 ; i < this->_tokens.size(); i++) {
                realname += " " + this->_tokens[i] ;
            }
            realname = this->_trim(realname);

            // Si empieza por ':', quitarlo
            if (!realname.empty() && realname[0] == ':')
                realname.erase(0,1);

            // Guarda al menos el username
            
            Logger::getInstance().log("[DEBUG] USER trimmed: " + username.get());
            client->setUser(username.get());
            client->setRealName(realname) ;
            if ( ( modeflag == "0" ) || ( modeflag == "4" ) || 
                 ( modeflag == "8" ) || ( modeflag == "12") ) {
                client->setUsermode(modeflag) ;
            } else {
                modeflag = "0" ;
                client->setUsermode(modeflag) ;
            }

            Logger::getInstance().log("[DEBUG] USER set username=" + 
                                    username.get() + " User mode=" +
                                    client->getUsermode() + " host=" + 
                                    client->getHost() + " fd=" + 
                                    fd_string);       
            // Intentamos registrar al cliente si está listo
            _server.tryRegister(*client);
        } catch (std::exception& e) {
            client->enqueueIrcMessage(
                this->_mm.Fmt_ERR_ERRONEUSUSERNAME(this->_tokens[1]) );
        }     
    } else {
        client->enqueueIrcMessage(this->_mm.Fmt_ERR_ALREADYREGISTRED()) ;
    }
} // function end
