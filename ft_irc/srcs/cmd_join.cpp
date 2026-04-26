#include "Parser.class.hpp"

/*
3.2.1 Join message

      Command: JOIN
   Parameters: ( <channel> *( "," <channel> ) [ <key> *( "," <key> ) ] )
               / "0"

   The JOIN command is used by a user to request to start listening to
   the specific channel.  Servers MUST be able to parse arguments in the
   form of a list of target, but SHOULD NOT use lists when sending JOIN
   messages to clients.

   Once a user has joined a channel, he receives information about
   all commands his server receives affecting the channel.  This
   includes JOIN, MODE, KICK, PART, QUIT and of course PRIVMSG/NOTICE.
   This allows channel members to keep track of the other channel
   members, as well as channel modes.

   If a JOIN is successful, the user receives a JOIN message as
   confirmation and is then sent the channel's topic (using RPL_TOPIC) and
   the list of users who are on the channel (using RPL_NAMREPLY), which
   MUST include the user joining.

   Note that this message accepts a special argument ("0"), which is
   a special request to leave all channels the user is currently a member
   of.  The server will process this message as if the user had sent
   a PART command (See Section 3.2.2) for each channel he is a member
   of.

   Numeric Replies:

           ERR_NEEDMOREPARAMS      OK      ERR_BANNEDFROMCHAN
           ERR_INVITEONLYCHAN              ERR_BADCHANNELKEY
           ERR_CHANNELISFULL               ERR_BADCHANMASK
           ERR_NOSUCHCHANNEL               ERR_TOOMANYCHANNELS
           ERR_TOOMANYTARGETS              ERR_UNAVAILRESOURCE
           RPL_TOPIC

   Examples:

   JOIN #foobar                    ; Command to join channel #foobar.

   JOIN &foo fubar                 ; Command to join channel &foo using
                                   key "fubar".

   JOIN #foo,&bar fubar            ; Command to join channel #foo using
                                   key "fubar" and &bar using no key.

   JOIN #foo,#bar fubar,foobar     ; Command to join channel #foo using
                                   key "fubar", and channel #bar using
                                   key "foobar".

   JOIN #foo,#bar                  ; Command to join channels #foo and
                                   #bar.

   JOIN 0                          ; Leave all currently joined
                                   channels.

   :WiZ!jto@tolsun.oulu.fi JOIN #Twilight_zone ; JOIN message from WiZ
                                   on channel #Twilight_zone
*/

void Parser::_cmd_join(Client * client)
{
    if (!client->isRegistered()) {
        client->enqueueIrcMessage(this->_mm.Fmt_ERR_NOTREGISTERED ());
        return ;
    }

    if (this->_tokens.size() == 1) {
        client->enqueueIrcMessage(
            this->_mm.Fmt_ERR_NEEDMOREPARAMS (this->_tokens[0]));
        return ;
    }

    if (this->_tokens.size() == 2 && this->_tokens[1] == "0") 
    {      
        _server.leaveAllChannels(*client);
        _server.purgeChannels();
        _server.debugChannels() ;
        return ;
    } 
    std::vector<std::string> lista_canales = this->_splitString(this->_tokens[1], ',') ;
    std::vector<std::string> lista_keys;// = this->_splitString(this->_tokens[2], ',') ;
    if (this->_tokens.size() == 3)
    {
        lista_keys = this->_splitString(this->_tokens[2], ',');
    }
    for (size_t i = 0; i < lista_canales.size() ; i++) 
    {

        bool ctrl = true;
        bool has_room = true;
        bool is_member = false;
        try 
        {
            ChanName _channelname(lista_canales[i]) ;
            if (_channelname.get()[0] != '#')
            {
                client->enqueueIrcMessage(
                    this->_mm.Fmt_ERR_NOSUCHCHANNEL(_channelname.get()) + ". Prefix not supported in this academic exercise ;-)");
                    return;
            }
            Channel*  _channelptr = _server.findChannel(_channelname.get()) ;
            if ( _channelptr == NULL) {
                Channel &_channelref = _server.createChannel(_channelname.get()) ;
                client->enqueueIrcMessage(
                    this->_mm.Fmt_RPL_JOIN( client->getNick(),
                                            client->getUser(),
                                            client->getHost(),
                                                _channelname.get()) );
                if (i < lista_keys.size() && lista_keys[i] != "0") ///
                {
                    _channelref.SetKeyRequired(lista_keys[i]) ;
                    client->enqueueIrcMessage(this->_mm.Fmt_RPL_CHANNELMODEIS(
                        client->getNick(),
                        _channelname.get(),
                        "+k",
                        lista_keys[i]));
                }
                else
                {
                    client->enqueueIrcMessage(this->_mm.Fmt_RPL_CHANNELMODEIS(
                        client->getNick(),                        
                        _channelname.get(),
                        "",
                        ""));

                }
                ctrl = _channelref.AddMember(client) ;
                std::vector<Client*> _channelmembers = _channelref.getMembers();
                std::string namesList = "";
                for (size_t j = 0; j < _channelmembers.size(); j++) 
                {
                    if (j > 0) namesList += " ";
                    if (_channelref.isAdmin(_channelmembers[j]))
                    {
                        namesList += "@";
                    }
                    namesList += _channelmembers[j]->getNick();
                }
                client->enqueueIrcMessage(
                        this->_mm.Fmt_RPL_TOPIC(client->getNick(), _channelname.get(), ""));
                client->enqueueIrcMessage(
                        this->_mm.Fmt_RPL_NAMREPLY(client->getNick(), _channelname.get(), namesList));
                client->enqueueIrcMessage(
                        this->_mm.Fmt_RPL_ENDOFNAMES(client->getNick(), _channelname.get()));
                _server.debugChannels() ;
            } 
            else 
            {
                ctrl = (false || _channelptr->isInvited(client));
                if (_channelptr->isMember(client))
                {
                    ctrl = false;
                    is_member = true;
                }
                else if (_channelptr->isInviteOnly() && !_channelptr->isInvited(client))
                {
                    client->enqueueIrcMessage(this->_mm.Fmt_ERR_INVITEONLYCHAN(_channelname.get()));
                    has_room = false;
                    continue ;
                }
                else if (!_channelptr->isInvited(client))
                {
                    if ((_channelptr->getSizeChannel() == _channelptr->getUserLimit()) || 
                    (_channelptr->getUserLimit() > 0 && (_channelptr->getSizeChannel() + 1) > _channelptr->getUserLimit()))
                    {
                        client->enqueueIrcMessage(this->_mm.Fmt_ERR_CHANNELISFULL(_channelname.get()));
                        has_room = false;
                    }
                }
                if (!is_member && _channelptr->isKeyProtected() && (this->_tokens.size() != 3 || lista_keys[i] != _channelptr->getKey()))
                {
                    ctrl = false;
                    client->enqueueIrcMessage(this->_mm.Fmt_ERR_BADCHANNELKEY(_channelname.get()));
                }
                else if (!is_member && _channelptr->isKeyProtected() && (lista_keys[i] == _channelptr->getKey()))
                {
                    ctrl = true;
                }
                else if (!is_member && !_channelptr->isKeyProtected())
                {
                    ctrl = true;
                }
                if (ctrl && has_room)
                {
                    _channelptr->AddMember(client);
                    // std::string joinMsg = ":" + client->getNick() + "!" + 
                    //  client->getUser() + "@" + client->getHost() + 
                    //  " JOIN :" + _channelname.get();
                    client->enqueueIrcMessage(
                        this->_mm.Fmt_RPL_JOIN( client->getNick(),
                                                client->getUser(),
                                                client->getHost(),
                                                _channelname.get()) );
                    // if (!_channelptr->getTopic().empty()) 
                    // {
                    //     client->enqueueIrcMessage(this->_mm.Fmt_RPL_TOPIC(_channelname.get(), 
                    //             _channelptr->getTopic()));
                    // }
                    client->enqueueIrcMessage(
                        this->_mm.Fmt_RPL_TOPIC(client->getNick(), _channelname.get(), _channelptr->getTopic()));
                    std::vector<Client*> _channelmembers = _channelptr->getMembers();
                    std::string namesList = "";
                    for (size_t j = 0; j < _channelmembers.size(); j++) {
                        if (j > 0) namesList += " ";
                        // Add @ prefix for admins
                        if (_channelptr->isAdmin(_channelmembers[j])) {
                            namesList += "@";
                        }
                        namesList += _channelmembers[j]->getNick();
                    }    
                    client->enqueueIrcMessage(
                        this->_mm.Fmt_RPL_NAMREPLY(client->getNick(), _channelname.get(), namesList));
                    client->enqueueIrcMessage(
                        this->_mm.Fmt_RPL_ENDOFNAMES(client->getNick(), _channelname.get()));
                    _channelptr->broadcastMessage(
                        this->_mm.Fmt_RPL_JOIN( client->getNick(),
                                                client->getUser(),
                                                client->getHost(),
                                                _channelname.get()),client );
                }                        
                _server.debugChannels() ;                                    
            }
        }
        catch (const std::exception& e ) 
        {
            std::stringstream ss;
            ss << "Channel Name error: " << e.what() ;
            client->enqueueIrcMessage(ss.str()) ;                
        }
    }
}