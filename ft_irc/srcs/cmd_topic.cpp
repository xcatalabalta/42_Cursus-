#include "Parser.class.hpp"


/*
3.2.4 Topic message

      Command: TOPIC
   Parameters: <channel> [ <topic> ]

   The TOPIC command is used to change or view the topic of a channel.
   The topic for channel <channel> is returned if there is no <topic>
   given.  If the <topic> parameter is present, the topic for that
   channel will be changed, if this action is allowed for the user
   requesting it.  If the <topic> parameter is an empty string, the
   topic for that channel will be removed.

   Numeric Replies:

           ERR_NEEDMOREPARAMS      OK        ERR_NOTONCHANNEL    OK
           RPL_NOTOPIC             OK        RPL_TOPIC           OK
           ERR_CHANOPRIVSNEEDED    OK        ERR_NOCHANMODES

   Examples:

   :WiZ!jto@tolsun.oulu.fi TOPIC #test :New topic ; User Wiz setting the
                                   topic.

   TOPIC #test :another topic      ; Command to set the topic on #test
                                   to "another topic".

   TOPIC #test :                   ; Command to clear the topic on
                                   #test.

   TOPIC #test                     ; Command to check the topic for
                                   #test.
*/

void Parser::_cmd_topic(Client * client)
{
    std::stringstream msg;
    std::string _channelname_str ;
    Channel*  _channelptr;
    // std::cout << "TOPIC detectado con estos parametros" << std::endl;
    // msg << "TOPIC detectado con estos parametros" << std::endl;
    // for (size_t i = 1; i < this->_tokens.size(); ++i) {
    //     msg << this->_tokens[i] << std::endl;
    //     std::cout << this->_tokens[i] << std::endl;
    // }
    // msg << this->_txt_line ;
	// client->enqueueIrcMessage(msg.str());
    
    if (!client->isRegistered()) {
        client->enqueueIrcMessage(this->_mm.Fmt_ERR_NOTREGISTERED ());
        return ;
    }
    
    if (this->_tokens.size() == 1) {
        client->enqueueIrcMessage(
            this->_mm.Fmt_ERR_NEEDMOREPARAMS(this->_tokens[0]));
        return ;
    }

    try {
        ChanName _channel(this->_tokens[1]) ;
        _channelname_str = _channel.get() ;
        Channel*  __channelptr = _server.findChannel(_channelname_str) ;
        if ( __channelptr == NULL ) {   
            client->enqueueIrcMessage(
                this->_mm.Fmt_ERR_NOSUCHCHANNEL(_channelname_str));
            return ;
            }
        _channelptr = __channelptr ;
    } catch (const std::exception& e) {
        // Catches if the name doesn't start with a valid prefix
        msg << "Channel Name error: " << e.what() ;
        client->enqueueIrcMessage(msg.str()) ;
        return ;
    }    

    if (this->_tokens.size() == 2) {
        //  TOPIC #test                  ; Command to check the topic for #test.
        std::string _topic = _channelptr->getTopic();
        if (_topic.empty()){
            client->enqueueIrcMessage(
                this->_mm.Fmt_RPL_NOTOPIC(_channelname_str)) ;
            return ;
        } else {
            client->enqueueIrcMessage(
                this->_mm.Fmt_RPL_TOPIC(
                client->getNick(),
                _channelname_str,
                _channelptr->getTopic()
            )) ;
            return ;
        }

    }
    // Only members can chang channel topic
    if (!(_channelptr->isMember(client))) {
        client->enqueueIrcMessage(
                this->_mm.Fmt_ERR_NOTONCHANNEL( _channelname_str ) ) ;
        return ; 
    }

    // In channels restricted to a topic only adminstrators change topic
    if ((_channelptr->isTopicRestricted()) && !(_channelptr->isAdmin(client))) {
        client->enqueueIrcMessage(
                this->_mm.Fmt_ERR_CHANOPRIVSNEEDED( _channelname_str ) ) ;
        return ; 
    }

    if (this->_tokens.size() == 3 && (this->_tokens[2] == ":")) {
    //  TOPIC #test :                ; Command to clear the topic on #test.
        _channelptr->SetTopic("") ;
        std::string msg = this->_mm.Fmt_RPL_TOPIC(
                client->getNick(),
                _channelname_str,
                _channelptr->getTopic() );
        client->enqueueIrcMessage( msg ) ;
        
        _channelptr->broadcastMessage(msg, NULL);
        return ;
    }

    //  TOPIC #test :another topic      ; Command to set the topic on #test
    //                                     to "another topic".
                     
    std::string n_top = this->_tokens[2].substr(1);
    for (size_t i = 3 ; i < this->_tokens.size(); i++) {
        n_top = n_top + " " +this->_tokens[i] ;
    }
    n_top = this->_trim(n_top);
    _channelptr->SetTopic(n_top) ;
    std::string msg2 = this->_mm.Fmt_RPL_TOPIC(
                client->getNick(),
                _channelname_str,
                _channelptr->getTopic() );
        client->enqueueIrcMessage( msg2 ) ;
        
        _channelptr->broadcastMessage(msg2, NULL);
}
