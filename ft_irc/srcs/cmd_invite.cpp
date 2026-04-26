#include "Parser.class.hpp"


/*

3.2.7 Invite message

      Command: INVITE
   Parameters: <nickname> <channel>

   The INVITE command is used to invite a user to a channel.  The
   parameter <nickname> is the nickname of the person to be invited to
   the target channel <channel>.  There is no requirement that the
   channel the target user is being invited to must exist or be a valid
   channel.  However, if the channel exists, only members of the channel
   are allowed to invite other users.  When the channel has invite-only
   flag set, only channel operators may issue INVITE command.


   Only the user inviting and the user being invited will receive
   notification of the invitation.  Other channel members are not
   notified.  (This is unlike the MODE changes, and is occasionally the
   source of trouble for users.)

   Numeric Replies:

           ERR_NEEDMOREPARAMS  OK          ERR_NOSUCHNICK OK
           ERR_NOTONCHANNEL  OK            ERR_USERONCHANNEL OK
           ERR_CHANOPRIVSNEEDED
           RPL_INVITING   OK                 RPL_AWAY

   Examples:

   :Angel!wings@irc.org INVITE Wiz #Dust ; Message to WiZ when he has been invited by user Angel to channel #Dust

   INVITE Wiz #Twilight_Zone       ; Command to invite WiZ to #Twilight_zone
   
   */
void Parser::_cmd_invite(Client * client)
{
    // std::stringstream msg;
    // std::cout << "INVITE detectado con estos parametros" << std::endl;
    // msg << "INVITE detectado con estos parametros" << std::endl;
    // for (size_t i = 1; i < this->_tokens.size(); ++i) {
    //     msg << this->_tokens[i] << std::endl;
    //     std::cout << this->_tokens[i] << std::endl;
    // }
	// client->enqueueIrcMessage(msg.str());
    if (!client->isRegistered()) {
        client->enqueueIrcMessage(this->_mm.Fmt_ERR_NOTREGISTERED ());
        return ;
    }
    if (this->_tokens.size() < 3) {
        client->enqueueIrcMessage(
            this->_mm.Fmt_ERR_NEEDMOREPARAMS (this->_tokens[0]));
        return ;
    }
    try {
        // first verify if channel exists
        ChanName _channelname(this->_tokens[2]) ;
        Channel*  _channelptr = _server.findChannel(_channelname.get() ) ;
        if ( _channelptr == NULL ) {
            // There is not such channel.     
            client->enqueueIrcMessage(
                this->_mm.Fmt_ERR_NOSUCHCHANNEL(_channelname.get()));
            return ;
        }
        if ( _channelptr->isInviteOnly() ) {
            // This channel is invite only
            if ( ! _channelptr->isAdmin(client) ) {
                // This client is NOT a channel admin
                client->enqueueIrcMessage(
                    this->_mm.Fmt_ERR_CHANOPRIVSNEEDED(_channelname.get()));
                return ;
            }
        }
        if (_channelptr->isMember(client) ) {
            //This client is a channel a member
            try {
                std::string _chan_str = _channelname.get() ;

                NickName _nick(this->_tokens[1]) ;
                //Client * client_to_invite = _server.findNick(_nick.get()) ;
                Client * client_to_invite = _server.findNick(_nick) ;
                if ( client_to_invite == NULL ) {
                    // this nick does not exist
                    client->enqueueIrcMessage(
                        this->_mm.Fmt_ERR_NOSUCHNICK(_nick.get())) ;
                    return ;
                }
                std::string _nick_str = _nick.get() ;
                _channelptr->AddInvite(client_to_invite) ;
                //_server.sendPrivateMessage(client, _nick.get(), this->_mm.Fmt_RPL_INVITING( client->getNick(),_channelname.get(), _nick.get()) );
                client_to_invite->enqueueIrcMessage(
                    this->_mm.Fmt_RPL_INVITED( 
                        client->getNick(),
                        client->getUser(),
                        client->getHost(),
                        _nick_str,
                        _chan_str));
                client->enqueueIrcMessage(
                    this->_mm.Fmt_RPL_INVITING(
                        client->getNick(),
                        _chan_str,
                        _nick_str));
            } catch  (const std::exception& e ) {
                std::stringstream ss;
                ss << "Nick Name error: " << e.what() ;
                client->enqueueIrcMessage(ss.str()) ;                
            }
       
        } else {
            // This client is NOT a channel a member
            client->enqueueIrcMessage(this->_mm.Fmt_ERR_NOTONCHANNEL(_channelname.get()));
            return ;           
        }

    } catch  (const std::exception& e ) {
        std::stringstream ss;
        ss << "Channel Name error: " << e.what() ;
        client->enqueueIrcMessage(ss.str()) ;                
    }


}
