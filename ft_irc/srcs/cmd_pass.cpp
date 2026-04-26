#include "Parser.class.hpp"


/*
3.1.1 Password message

      Command: PASS
   Parameters: <password>

   The PASS command is used to set a 'connection password'.  The
   optional password can and MUST be set before any attempt to register
   the connection is made.  Currently this requires that user send a
   PASS command before sending the NICK/USER combination.

   Numeric Replies:

           ERR_NEEDMOREPARAMS              ERR_ALREADYREGISTRED

   Example:

           PASS secretpasswordhere

           */
void Parser::_cmd_pass(Client * client)
{
    // std::stringstream msg;
    // std::cout << "PASS detectado con estos parametros" << std::endl;
    // msg << "PASS detectado con estos parametros" << std::endl;
    // for (size_t i = 1; i < this->_tokens.size(); ++i) {
    //     msg << this->_tokens[i] << std::endl;
    //     std::cout << this->_tokens[i] << std::endl;
    // }
    if (this->_tokens.size() == 1) {
        client->enqueueIrcMessage(
            this->_mm.Fmt_ERR_NEEDMOREPARAMS(this->_tokens[0]));
    }
    else if (this->_tokens.size() == 2) {
        if (!client->isPassAccepted() ) {
            if (this->_tokens[1] == this->_server.getPassword()) {
                std::stringstream ss ;
                ss << client->getFd() ;
                client->setPassAccepted(true);
                Logger::getInstance().log(
                    "[DEBUG] Password accepted for fd=" + ss.str());
            } else {
                client->setPassAccepted(false);

                client->enqueueIrcMessage(this->_mm.Fmt_ERR_PASSWDMISMATCH());
            }
            // Intentamos registrar el cliente si está listo
            this->_server.tryRegister(*client);
        } else {
            client->enqueueIrcMessage(this->_mm.Fmt_ERR_ALREADYREGISTRED()) ;
        }
    }
    else {
        client->enqueueIrcMessage(this->_mm.Fmt_ERR_PASSWDMISMATCH());
    }
}
