#include "Parser.class.hpp"

/*


3.3.1 Private messages

      Command: PRIVMSG
   Parameters: <msgtarget> <text to be sent>

   PRIVMSG is used to send private messages between users, as well as to
   send messages to channels.  <msgtarget> is usually the nickname of
   the recipient of the message, or a channel name.

   The <msgtarget> parameter may also be a host mask (#<mask>) or server
   mask ($<mask>).  In both cases the server will only send the PRIVMSG
   to those who have a server or host matching the mask.  The mask MUST
   have at least 1 (one) "." in it and no wildcards following the last
   ".".  This requirement exists to prevent people sending messages to
   "#*" or "$*", which would broadcast to all users.  Wildcards are the
   '*' and '?'  characters.  This extension to the PRIVMSG command is
   only available to operators.

   Numeric Replies:

           ERR_NORECIPIENT                 ERR_NOTEXTTOSEND
           ERR_CANNOTSENDTOCHAN            ERR_NOTOPLEVEL
           ERR_WILDTOPLEVEL                ERR_TOOMANYTARGETS
           ERR_NOSUCHNICK
           RPL_AWAY


   Examples:

   :Angel!wings@irc.org PRIVMSG Wiz :Are you receiving this message ?
                                   ; Message from Angel to Wiz.

   PRIVMSG Angel :yes I'm receiving it !
                                   ; Command to send a message to Angel.

   PRIVMSG jto@tolsun.oulu.fi :Hello !
                                   ; Command to send a message to a user
                                   on server tolsun.oulu.fi with
                                   username of "jto".

   PRIVMSG kalt%millennium.stealth.net@irc.stealth.net :Are you a frog?
                                   ; Message to a user on server
                                   irc.stealth.net with username of
                                   "kalt", and connected from the host
                                   millennium.stealth.net.

   PRIVMSG kalt%millennium.stealth.net :Do you like cheese?
                                   ; Message to a user on the local
                                   server with username of "kalt", and
                                   connected from the host
                                   millennium.stealth.net.

   PRIVMSG Wiz!jto@tolsun.oulu.fi :Hello !
                                   ; Message to the user with nickname
                                   Wiz who is connected from the host
                                   tolsun.oulu.fi and has the username
                                   "jto".

   PRIVMSG $*.fi :Server tolsun.oulu.fi rebooting.
                                   ; Message to everyone on a server
                                   which has a name matching *.fi.

   PRIVMSG #*.edu :NSFNet is undergoing work, expect interruptions
                                   ; Message to all users who come from
                                   a host which has a name matching
                                   *.edu.



    void sendMessageToChannel(Client* sender, 
            const std::string& channelName, 
            const std::string& message);


*/

void Parser::_cmd_privmsg_user(Client * client, NickName & _nick)
{
    Client * client_to_talk = _server.findNick(_nick) ;
    if ( client_to_talk == NULL ) {
        // this nick does not exist
        client->enqueueIrcMessage(this->_mm.Fmt_ERR_NOSUCHNICK(_nick.get())) ;
        return ;
    }

    std::string mensa = this->_tokens[2];
    if (mensa[0] == ':')
    {
        mensa.erase(mensa.begin());
    }

    for (size_t i = 3; i < this->_tokens.size(); ++i) 
    {
        mensa = mensa + " " + this->_tokens[i];
    }

    _server.sendPrivateMessage(client, _nick.get(), mensa);

    // std::stringstream msg;
    // std::string destin;
    // std::string mensa;
    //std::cout << "PRIVMSG detectado con estos parametros" << std::endl;
    //msg << "PRIVMSG detectado con estos parametros" << std::endl;
	//    for (size_t i = 1; i < this->_tokens.size(); ++i) 
    // {
    //     if (i == 1)
    //     {
    //         destin = this->_tokens[i];
    //     }
    //     else
    //     {
    //         mensa += this->_tokens[i];
    //         if (i + 1 < this->_tokens.size())
    //             mensa += " ";
    //     }
    //     msg << this->_tokens[i] << std::endl;
    //     //std::cout << this->_tokens[i] << std::endl;
    // }
	// //client->enqueueIrcMessage(msg.str());//GARBAGE
    // //sin control de errores
    // if (mensa[0] == ':')
    // {
    //     mensa.erase(mensa.begin());
    // }
    // //std::cout   << "[DEBUG PRIV] "<< client->getNick() << " sends " << mensa 
    // //            << " to " << destin << std::endl;
    
    // ChanName destiny(destin);
    // Channel* canal = _server.findChannel(destiny.get());
    // if (canal == NULL)
    // {
    //     std::cout << "tas colao pescao\n";
    // }
    // else
    // {
    //     canal->broadcastMessage(mensa,client);
    // }
    // return ;
}
