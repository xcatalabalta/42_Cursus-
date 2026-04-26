#include "Parser.class.hpp"

void Parser::_cmd_privmsg(Client * client)
{

    if (!client->isRegistered()) {
        client->enqueueIrcMessage(this->_mm.Fmt_ERR_NOTREGISTERED ());
        return ;
    }

    if (this->_tokens.size() < 3) {
            client->enqueueIrcMessage(
                this->_mm.Fmt_ERR_NEEDMOREPARAMS (this->_tokens[0]));
        return ;
    }
    // PRIVMSG  <user/channel> <text to be sent>
    try {
        // Check if it is a User mode command
        std::cout << "[DEBUG PRIVMSG] token[0] = " << this->_tokens[0] << " token[1] = "<< this->_tokens[1] << " token[2] = "<< this->_tokens[2] << std::endl;
        NickName _nick(this->_tokens[1]) ;
        _cmd_privmsg_user(client, _nick) ;
    } catch  (const std::exception& e ) {
        try {
            // check if it is a Channel mode command
            ChanName _channelname(this->_tokens[1]) ;
            _cmd_privmsg_channel(client, _channelname) ;
        }catch (const std::exception& e) {
            std::stringstream ss;
                ss << "No Nich Name or Channel Name here: " << e.what() ;
                client->enqueueIrcMessage(ss.str()) ;                
            }
    }
}
