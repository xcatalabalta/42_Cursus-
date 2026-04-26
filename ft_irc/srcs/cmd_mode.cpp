#include "Parser.class.hpp"

void Parser::_cmd_mode(Client * client)
{

    if (!client->isRegistered()) {
        client->enqueueIrcMessage(this->_mm.Fmt_ERR_NOTREGISTERED ());
        return ;
    }
    //MODE                       ; returns current user flags;
    if (this->_tokens.size() == 1) {
        client->enqueueIrcMessage(
            this->_mm.Fmt_RPL_UMODEIS(client->getUsermode()) );
        return ;
    }
    // MODE <user/channel> modeflags
    try {
        // Check if it is a User mode command
        NickName _nick(this->_tokens[1]) ;
        _cmd_mode_user(client, _nick) ;
    } catch  (const std::exception& e ) {
        try {
            // check if it is a Channel mode command
            ChanName _channelname(this->_tokens[1]) ;
            _cmd_mode_channel(client, _channelname) ;
        }catch (const std::exception& e) {
            std::stringstream ss;
                ss << "No Nich Name or Channel Name here: " << e.what() ;
                client->enqueueIrcMessage(ss.str()) ;                
            }
    }
}
