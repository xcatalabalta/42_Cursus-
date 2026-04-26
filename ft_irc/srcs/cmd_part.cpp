#include "Parser.class.hpp"

/*
3.2.2 Part message

      Command: PART
   Parameters: <channel> *( "," <channel> ) [ <Part Message> ]

   The PART command causes the user sending the message to be removed
   from the list of active members for all given channels listed in the
   parameter string.  If a "Part Message" is given, this will be sent
   instead of the default message, the nickname.  This request is always
   granted by the server.

   Servers MUST be able to parse arguments in the form of a list of
   target, but SHOULD NOT use lists when sending PART messages to
   clients.

   Numeric Replies:

           ERR_NEEDMOREPARAMS              ERR_NOSUCHCHANNEL
           ERR_NOTONCHANNEL

   Examples:

   PART #twilight_zone             ; Command to leave channel
                                   "#twilight_zone"

   PART #oz-ops,&group5            ; Command to leave both channels
                                   "&group5" and "#oz-ops".

   :WiZ!jto@tolsun.oulu.fi PART #playzone :I lost
                                   ; User WiZ leaving channel
                                   "#playzone" with the message "I
                                   lost".
*/
/*
void Parser::_cmd_part(Client * client)
{
    if (!client->isRegistered()) {
        client->enqueueIrcMessage(this->_mm.Fmt_ERR_NOTREGISTERED ());
        return ;
    }
    if (this->_tokens.size() == 1) {
        client->enqueueIrcMessage(this->_mm.Fmt_ERR_NEEDMOREPARAMS(this->_tokens[0]));
    }    
    if (this->_tokens.size() == 2) {
        std::vector<std::string> lista_canales = this->_splitString(this->_tokens[1], ',') ;
        for (size_t i = 0; i < lista_canales.size() ; i++) {
            try {
                ChanName _channelname(lista_canales[i]) ;
                Channel*  _channelptr = _server.findChannel(_channelname.get() ) ;
                if ( _channelptr == NULL ) {
                    client->enqueueIrcMessage(this->_mm.Fmt_ERR_NOSUCHCHANNEL(_channelname.get()) );
                    return ;
                }
                if (!_channelptr->isMember(client) ){
                    client->enqueueIrcMessage(this->_mm.Fmt_ERR_NOTONCHANNEL(_channelname.get()) );
                    return ;
                }
                //client->enqueueIrcMessage(this->_mm.Fmt_ERR_NOTONCHANNEL(_channelname.get()) );
                //if (_channelptr->getSizeChannel() == 0) {_channelptr->~Channel() ; }
                std::string partMsg = ":" + client->getNick() + "!" + 
                                 client->getUser() + "@" + client->getHost() + 
                                 " PART " + _channelptr->getName() + " :Leaving the channel";
                client->enqueueIrcMessage(partMsg);
                _channelptr->broadcastMessage(partMsg, client);
                _channelptr->RemoveMember(client) ;
                _server.purgeChannels();
                _server.debugChannels() ;


            } catch (const std::exception& e ) {
                std::stringstream ss;
                ss << "Channel Name error: " << e.what() ;
                client->enqueueIrcMessage(ss.str()) ;                
            }            
        }
    }
    if (this->_tokens.size() == 3) {
        std::vector<std::string> lista_canales = this->_splitString(this->_tokens[1], ',') ;
        std::vector<std::string> lista_motivos = this->_splitString(this->_tokens[2], ',') ;
        for (size_t i = 0; i < lista_canales.size() ; i++) {
            try {
                ChanName _channelname(lista_canales[i]) ;
                Channel*  _channelptr = _server.findChannel(_channelname.get() ) ;
                if ( _channelptr == NULL ) {
                    client->enqueueIrcMessage(this->_mm.Fmt_ERR_NOSUCHCHANNEL(_channelname.get()) );
                    return ;
                }
                if (!_channelptr->isMember(client) ){
                    client->enqueueIrcMessage(this->_mm.Fmt_ERR_NOTONCHANNEL(_channelname.get()) );
                    return ;
                }
                _channelptr->RemoveMember(client) ;
                //if (_channelptr->getSizeChannel() == 0) {_channelptr->~Channel() ; }
                _server.purgeChannels();
                _server.debugChannels() ;


            } catch (const std::exception& e ) {
                std::stringstream ss;
                ss << "Channel Name error: " << e.what() ;
                client->enqueueIrcMessage(ss.str()) ;                
            }                 
        }        
    }    
       
    
    return ;
}
*/
void Parser::_cmd_part(Client * client)
{
    if (!client->isRegistered()) {
        client->enqueueIrcMessage(this->_mm.Fmt_ERR_NOTREGISTERED());
        return;
    }
    if (this->_tokens.size() < 2) {
        client->enqueueIrcMessage(this->_mm.Fmt_ERR_NEEDMOREPARAMS(this->_tokens[0]));
        return;
    }

    // Split channel list
    std::vector<std::string> channels = this->_splitString(this->_tokens[1], ',');
    // Optional reasons (if provided)
    std::vector<std::string> reasons;
    if (this->_tokens.size() >= 3)
        reasons = this->_splitString(this->_tokens[2], ',');

    for (size_t i = 0; i < channels.size(); ++i) {
        try {
            ChanName cname(channels[i]);
            Channel* chan = _server.findChannel(cname.get());

            if (chan == NULL) {
                client->enqueueIrcMessage(this->_mm.Fmt_ERR_NOSUCHCHANNEL(cname.get()));
                continue;  // don’t kill whole loop
            }
            if (!chan->isMember(client)) {
                client->enqueueIrcMessage(this->_mm.Fmt_ERR_NOTONCHANNEL(cname.get()));
                continue;  //skip just this channel
            }

            // Reason: use supplied or default to "Leaving"
            std::string reason = (i < reasons.size()) ? reasons[i] : "Leaving";

            // Build PART message
            // std::string partMsg = ":" + client->getNick() + "!" +
            //                       client->getUser() + "@" + client->getHost() +
            //                       " PART " + chan->getName() + " :" + reason;
            std::string partMsg = this->_mm.Fmt_RPL_PART(
                                client->getNick(),
                                client->getUser(),
                                client->getHost(),
                                chan->getName(),
                                reason ) ;
            // Send PART to the leaver and to everyone else
            client->enqueueIrcMessage(partMsg);
            chan->broadcastMessage(partMsg, client);

            // Remove user and clean up
            chan->RemoveMember(client);
            _server.purgeChannels();
            _server.debugChannels();
        }
        catch (const std::exception& e) {
            std::stringstream ss;
            ss << "Channel Name error: " << e.what();
            client->enqueueIrcMessage(ss.str());
        }
    }
}
