#include "Parser.class.hpp"


/*
3.1.2 Nick message


      Command: NICK
   Parameters: <nickname>

   NICK command is used to give user a nickname or change the existing
   one.




Kalt                         Informational                     [Page 10]


RFC 2812          Internet Relay Chat: Client Protocol        April 2000


   Numeric Replies:

           ERR_NONICKNAMEGIVEN             ERR_ERRONEUSNICKNAME
           ERR_NICKNAMEINUSE               ERR_NICKCOLLISION
           ERR_UNAVAILRESOURCE             ERR_RESTRICTED

   Examples:

   NICK Wiz                ; Introducing new nick "Wiz" if session is
                           still unregistered, or user changing his
                           nickname to "Wiz"

   :WiZ!jto@tolsun.oulu.fi NICK Kilroy
                           ; Server telling that WiZ changed his
                           nickname to Kilroy.
*/
void Parser::_cmd_nick(Client * client)
{

    if (this->_tokens.size() == 1) {
        client->enqueueIrcMessage(this->_mm.Fmt_ERR_NONICKNAMEGIVEN ());
        return ;
    }

    // if (this->_tokens[1] == "Welcome"){
    //     // Client try to reconect after a timeout
    //     return ;
    // }

    try {
        NickName _nick(this->_tokens[1]) ;
        // Code to run if validation is successful
        try {
            // if (!client->hasNick()){
            //     client->setNick(this->_tokens[1]);
            //     std::cout << "[DEBUG] NICK set to " << this->_tokens[1] ;
            //     std::cout << " for fd=" << client->getFd() << std::endl;
            // } else {
            //     client->enqueueIrcMessage(
            //    this->_mm.Fmt_ERR_ALREADYREGISTRED()) ;
            // }
            Client * _client_check = _server.findNick(_nick) ;
            if ( _client_check == NULL) {
                client->setNick(this->_tokens[1]);
            } else {
                client->enqueueIrcMessage(
                    this->_mm.Fmt_ERR_NICKNAMEINUSE(_nick.get())) ;
                return ;
            }
            _server.debugPrintClients();
        } catch (const std::exception& e) {
            NickName nick(this->_tokens[1]);
            client->enqueueIrcMessage(
                this->_mm.Fmt_ERR_ERRONEUSNICKNAME(nick.get()));
            return;
        }
        // Intentamos registrar el cliente si está listo
        _server.tryRegister(*client);
    } catch (const std::invalid_argument& e) {
        std::stringstream ss;
        ss << "Invalid Nick: " << e.what() ;
        client->enqueueIrcMessage(ss.str()) ;
        // Handle the specific error (e.g., return a different message to the user)
    }

}
