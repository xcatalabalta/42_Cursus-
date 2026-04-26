#include "Parser.class.hpp"

/*
3.2.8 Kick command

      Command: KICK
   Parameters: <channel> *( "," <channel> ) <user> *( "," <user> )
               [<comment>]

   The KICK command can be used to request the forced removal of a user
   from a channel.  It causes the <user> to PART from the <channel> by
   force.  For the message to be syntactically correct, there MUST be
   either one channel parameter and multiple user parameter, or as many
   channel parameters as there are user parameters.  If a "comment" is
   given, this will be sent instead of the default message, the nickname
   of the user issuing the KICK.

   The server MUST NOT send KICK messages with multiple channels or
   users to clients.  This is necessarily to maintain backward
   compatibility with old client software.

   Numeric Replies:

           ERR_NEEDMOREPARAMS     OK       ERR_NOSUCHCHANNEL  OK
           ERR_BADCHANMASK                 ERR_CHANOPRIVSNEEDED
           ERR_USERNOTINCHANNEL            ERR_NOTONCHANNEL

   Examples:

   KICK &Melbourne Matthew         ; Command to kick Matthew from
                                   &Melbourne

   KICK #Finnish John :Speaking English
                                   ; Command to kick John from #Finnish
                                   using "Speaking English" as the
                                   reason (comment).

   :WiZ!jto@tolsun.oulu.fi KICK #Finnish John
                                   ; KICK message on channel #Finnish
                                   from WiZ to remove John from channel*/
/*
void Parser::_cmd_kick(Client * client)
{
    std::stringstream msg;
    std::string msgIrc = ":";

    if (!client->isRegistered()) {
        client->enqueueIrcMessage(this->_mm.Fmt_ERR_NOTREGISTERED ());
        return ;
    }
    if (this->_tokens.size() < 3) {
        client->enqueueIrcMessage(
            this->_mm.Fmt_ERR_NEEDMOREPARAMS (this->_tokens[0]));
        return ;
    }
    std::vector<std::string> l_can = this->_splitString(this->_tokens[1], ',') ;
    std::vector<std::string> l_use = this->_splitString(this->_tokens[2], ',') ;

    // For the message to be syntactically correct, there MUST be
    // either one channel parameter and multiple user parameter, or as many
    // channel parameters as there are user parameters
    if ( !((l_can.size() == 1 && l_use.size() >= 1) || 
        (l_can.size() == l_use.size())) ) {
        client->enqueueIrcMessage(
            this->_mm.Fmt_ERR_NEEDMOREPARAMS (this->_tokens[0]));
        return ;            
    }

    
    std::string comment ;
    if (this->_tokens.size() > 3) {
        comment = this->_tokens[3];
        for (size_t i = 3 ; i < this->_tokens.size(); i++) {
            comment = comment + " " +this->_tokens[i] ;
        }
    }

    if (l_can.size() == 1) {
        // KICK &Melbourne Matthew         ; kick Matthew from Melbourne
        // KICK &Melbourne Matthew,Peter   ; kick Matthew & Peter from Melbourne
        ChanName _channelname(l_can[0]) ;
        Channel*  _channelptr = _server.findChannel(l_can[0]) ;
        if ( _channelptr == NULL ) {
            // There is not such channel.
            client->enqueueIrcMessage(
                this->_mm.Fmt_ERR_NOSUCHCHANNEL(l_can[0]));
            return ;
        }

        if (!( _channelptr->isAdmin(client) ) )
        {
            // this cliente does not administrate this channel
            client->enqueueIrcMessage(
                this->_mm.Fmt_ERR_CHANOPRIVSNEEDED(l_can[0]));
            return ;
        }

        for (size_t u = 0; u < l_use.size(); u ++)
        {
            try
            {
                NickName _nick(l_use[u]);
                Client * client_to_kick = _server.findNick(_nick) ;
                if ( client_to_kick == NULL ) {
                    // this nick does not exist
                    client->enqueueIrcMessage(
                        this->_mm.Fmt_ERR_NOSUCHNICK(_nick.get())) ;
                    return ;
                } else if (!_channelptr->isMember(client_to_kick) ) {
                    client->enqueueIrcMessage(
                        this->_mm.Fmt_ERR_USERNOTINCHANNEL( 
                            _nick.get(), 
                            _channelname.get() ) );
                    return ;
                } else {

                    msg << "KICK " << l_can[0] << " " <<l_use[u] ;
                    msg << ":You have been kicked for " << comment ;
                    //KICK #mi_canal user_to_kick :You have been kicked for ...
                    msgIrc += "ueho";
                    client_to_kick->enqueueIrcMessage(msg.str());
                    _channelptr->broadcastMessage(msg.str(), client_to_kick);
                    _channelptr->RemoveMember(client_to_kick) ;
                    _server.sendPrivateMessage(
                        client, 
                        client_to_kick->getNick(),
                        msg.str()
                        ) ;
                    msg.str("") ;
                    msg.clear() ;
                }
            }
            catch(const std::exception& e)
            {
                std::stringstream ss;
                ss << "Nich Name error: " << e.what() ;
                client->enqueueIrcMessage(ss.str()) ;    
            }

        }
    } else { // both vectora have same size
        // KICK &aaa,#bbb Matthew,Peter   ; kick Matthew from #aaa 
        //                                ; kick Peter from #bbb        
        for (size_t c = 0; c < l_can.size() ; c++) 
        {
            ChanName _channelname(l_can[c]) ;
            Channel*  _channelptr = _server.findChannel(l_can[c]) ;
            if ( _channelptr == NULL ) {
                // There is not such channel.
                client->enqueueIrcMessage(
                    this->_mm.Fmt_ERR_NOSUCHCHANNEL(l_can[c]));
                return ;
            }

            if (!( _channelptr->isAdmin(client) ) )
            {
                client->enqueueIrcMessage(
                    this->_mm.Fmt_ERR_CHANOPRIVSNEEDED(l_can[c]));
                return ;
            }

            try
            {
                NickName _nick(l_use[c]);
                Client * client_to_kick = _server.findNick(_nick) ;
                if ( client_to_kick == NULL ) {
                    // this nick does not exist
                    client->enqueueIrcMessage(
                        this->_mm.Fmt_ERR_NOSUCHNICK(_nick.get())) ;
                    return ;
                } else if (!_channelptr->isMember(client_to_kick) ) {
                    client->enqueueIrcMessage(
                        this->_mm.Fmt_ERR_USERNOTINCHANNEL( 
                            _nick.get(), 
                            _channelname.get() ) );
                    return ;
                } else {

                    msg << "KICK " << l_can[c] << " " <<l_use[c] ;
                    msg << ":You have been kicked for " << comment ;
                    //KICK #mi_canal user_to_kick :You have been kicked for ...
                    _channelptr->RemoveMember(client_to_kick) ;
                    _server.sendPrivateMessage(
                        client, 
                        client_to_kick->getNick(),
                        msg.str()
                        ) ;
                    msg.str("") ;
                    msg.clear() ;
                }
            }
            catch(const std::exception& e)
            {
                std::stringstream ss;
                ss << "Nick Name error: " << e.what() ;
                client->enqueueIrcMessage(ss.str()) ;    
            }

        }  // for
    } // else
}
*/
void Parser::_cmd_kick(Client * client)
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
    
    std::vector<std::string> l_can = this->_splitString(this->_tokens[1], ',');
    std::vector<std::string> l_use = this->_splitString(this->_tokens[2], ',');
    
    // Validate syntax
    if (!((l_can.size() == 1 && l_use.size() >= 1) || 
        (l_can.size() == l_use.size()))) {
        client->enqueueIrcMessage(
            this->_mm.Fmt_ERR_NEEDMOREPARAMS (this->_tokens[0]));
        return;            
    }
    
    // Extract comment (kick reason)
    std::string comment = client->getNick(); // Default reason
    if (this->_tokens.size() > 3) {
        comment = this->_tokens[3];
        // Remove leading ':' if present
        if (!comment.empty() && comment[0] == ':') {
            comment = comment.substr(1);
        }
        // Append remaining tokens
        for (size_t i = 4; i < this->_tokens.size(); i++) {
            comment += " " + this->_tokens[i];
        }
    }
    
    if (l_can.size() == 1) {
        // Single channel, multiple users
        try {
            ChanName _channelname(l_can[0]);
            Channel* _channelptr = _server.findChannel(_channelname.get());
            
            if (_channelptr == NULL) {
                client->enqueueIrcMessage(
                    this->_mm.Fmt_ERR_NOSUCHCHANNEL(_channelname.get()));
                return;
            }
            
            if (!_channelptr->isAdmin(client)) {
                client->enqueueIrcMessage(
                    this->_mm.Fmt_ERR_CHANOPRIVSNEEDED(_channelname.get()));
                return;
            }
            
            for (size_t u = 0; u < l_use.size(); u++) {
                try {
                    NickName _nick(l_use[u]);
                    Client* client_to_kick = _server.findNick(_nick);
                    
                    if (client_to_kick == NULL) {
                        client->enqueueIrcMessage(
                            this->_mm.Fmt_ERR_NOSUCHNICK(_nick.get()));
                        continue; // Try next user instead of return
                    }
                    
                    if (!_channelptr->isMember(client_to_kick)) {
                        client->enqueueIrcMessage(
                            this->_mm.Fmt_ERR_USERNOTINCHANNEL(
                                _nick.get(), 
                                _channelname.get()));
                        continue;
                    }
                    
                    // Format proper KICK message
                    // std::string kickMsg = ":" + client->getNick() + "!" + 
                    //                      client->getUser() + "@" + client->getHost() + 
                    //                      " KICK " + _channelname.get() + " " + 
                    //                      _nick.get() + " :" + comment;
                    std::string kickMsg = this->_mm.Fmt_RPL_KICK(
                                client->getNick(),
                                client->getUser(),
                                client->getHost(),
                                _channelname.get(),
                               _nick.get(),
                                comment ) ;
                    // Send to kicked user
                    client_to_kick->enqueueIrcMessage(kickMsg);
                    /*
                    exchat says
                    << KICK IRC_42_01 #bbb :paquito
                    >> Channel Name error: Invalid prefix. 
                    A channel name must start with '#', '&', '!', or '+'.
                    */
                    // Broadcast to ALL channel members (including kicker)
                    _channelptr->sendToall(kickMsg);
                    
                    // Remove member AFTER sending messages
                    _channelptr->RemoveMember(client_to_kick);
                    
                } catch (const std::exception& e) {
                    std::stringstream ss;
                    ss << "Nick Name error: " << e.what();
                    client->enqueueIrcMessage(ss.str());
                }
            }
            
        } catch (const std::exception& e) {
            std::stringstream ss;
            ss << "Channel Name error: " << e.what();
            client->enqueueIrcMessage(ss.str());
        }
        
    } else {
        // Multiple channels, matching users
        for (size_t c = 0; c < l_can.size(); c++) {
            try {
                ChanName _channelname(l_can[c]);
                Channel* _channelptr = _server.findChannel(_channelname.get());
                
                if (_channelptr == NULL) {
                    client->enqueueIrcMessage(
                        this->_mm.Fmt_ERR_NOSUCHCHANNEL(_channelname.get()));
                    continue;
                }
                
                if (!_channelptr->isAdmin(client)) {
                    client->enqueueIrcMessage(
                        this->_mm.Fmt_ERR_CHANOPRIVSNEEDED(_channelname.get()));
                    continue;
                }
                
                try {
                    NickName _nick(l_use[c]);
                    Client* client_to_kick = _server.findNick(_nick);
                    
                    if (client_to_kick == NULL) {
                        client->enqueueIrcMessage(
                            this->_mm.Fmt_ERR_NOSUCHNICK(_nick.get()));
                        continue;
                    }
                    
                    if (!_channelptr->isMember(client_to_kick)) {
                        client->enqueueIrcMessage(
                            this->_mm.Fmt_ERR_USERNOTINCHANNEL(
                                _nick.get(), 
                                _channelname.get()));
                        continue;
                    }
                    
                    // Format proper KICK message
                    // std::string kickMsg = ":" + client->getNick() + "!" + 
                    //                      client->getUser() + "@" + client->getHost() + 
                    //                      " KICK " + _channelname.get() + " " + 
                    //                      _nick.get() + " :" + comment;
                    std::string kickMsg = this->_mm.Fmt_RPL_KICK(
                                client->getNick(),
                                client->getUser(),
                                client->getHost(),
                                _channelname.get(),
                               _nick.get(),
                                comment ) ;
                    
                    // Send to kicked user
                    client_to_kick->enqueueIrcMessage(kickMsg);
                    
                    // Broadcast to ALL channel members
                    _channelptr->sendToall(kickMsg);
                    
                    // Remove member AFTER sending messages
                    _channelptr->RemoveMember(client_to_kick);
                    
                } catch (const std::exception& e) {
                    std::stringstream ss;
                    ss << "Nick Name error: " << e.what();
                    client->enqueueIrcMessage(ss.str());
                }
                
            } catch (const std::exception& e) {
                std::stringstream ss;
                ss << "Channel Name error: " << e.what();
                client->enqueueIrcMessage(ss.str());
            }
        }
    }
    
    // Clean up empty channels
    _server.purgeChannels();
}