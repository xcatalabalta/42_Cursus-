#include "Parser.class.hpp"

/*
3.6.1 Who query

      Command: WHO
   Parameters: [ <mask> [ "o" ] ]

   The WHO command is used by a client to generate a query which returns
   a list of information which 'matches' the <mask> parameter given by
   the client.  In the absence of the <mask> parameter, all visible
   (users who aren't invisible (user mode +i) and who don't have a
   common channel with the requesting client) are listed.  The same
   result can be achieved by using a <mask> of "0" or any wildcard which
   will end up matching every visible user.

   The <mask> passed to WHO is matched against users' host, server, real
   name and nickname if the channel <mask> cannot be found.

   If the "o" parameter is passed only operators are returned according
   to the <mask> supplied.

   Numeric Replies:

           ERR_NOSUCHSERVER
           RPL_WHOREPLY                  RPL_ENDOFWHO

   Examples:

   WHO *.fi                        ; Command to list all users who match
                                   against "*.fi".

   WHO jto* o                      ; Command to list all users with a
                                   match against "jto*" if they are an
                                   operator.
*/
void Parser::_cmd_who(Client * client)
{
    // std::stringstream msg;
    // std::cout << "WHO detectado con estos parametros" << std::endl;
    // msg << "WHO detectado con estos parametros" << std::endl;
    // for (size_t i = 1; i < this->_tokens.size(); ++i) {
    //     msg << this->_tokens[i] << std::endl;
    //     std::cout << this->_tokens[i] << std::endl;
    // }
	// client->enqueueIrcMessage(msg.str());
    // return ;

    std::stringstream msg;
    std::string _channelname_str ;
    Channel*  _channelptr;    
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
    std::string cli_nick = client->getNick() ;
    std::string u_mode ="" ;
    std::string status = "H";
    std::string server = "ircserver";
    int hopcount = 0;
    std::vector<Client*> _channelmembers = _channelptr->getMembers();
    for (size_t j = 0; j < _channelmembers.size(); j++) {
        if (_channelptr->isAdmin(_channelmembers[j])) {u_mode = "@";}
        if ( j % 2  == 0 ) {status = "G" ; } else {status = "H" ;}
    
        client->enqueueIrcMessage(
            this->_mm.Fmt_RPL_WHOREPLY (cli_nick ,
                                        _channelname_str,
                                        _channelmembers[j]->getUser(),
                                        _channelmembers[j]->getHost(),                                        
                                        server,
                                        _channelmembers[j]->getNick(),
                                        status,
                                        u_mode,
                                        hopcount,
                                        _channelmembers[j]->getRealName()
                                        ));        
    }

    client->enqueueIrcMessage(
        this->_mm.Fmt_RPL_ENDOFWHO(cli_nick ,_channelname_str));
}
