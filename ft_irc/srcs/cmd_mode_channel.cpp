#include "Parser.class.hpp"



/*

3.2.3 Channel mode message

      Command: MODE
   Parameters: <channel> *( ( "-" / "+" ) *<modes> *<modeparams> )

   The MODE command is provided so that users may query and change the
   characteristics of a channel.  For more details on available modes
   and their uses, see "Internet Relay Chat: Channel Management" [IRC-
   CHAN].  Note that there is a maximum limit of three (3) changes per
   command for modes that take a parameter.

   Numeric Replies:

           ERR_NEEDMOREPARAMS              ERR_KEYSET
           ERR_NOCHANMODES                 ERR_CHANOPRIVSNEEDED
           ERR_USERNOTINCHANNEL            ERR_UNKNOWNMODE
           RPL_CHANNELMODEIS
           RPL_BANLIST                     RPL_ENDOFBANLIST
           RPL_EXCEPTLIST                  RPL_ENDOFEXCEPTLIST
           RPL_INVITELIST                  RPL_ENDOFINVITELIST
           RPL_UNIQOPIS

   The following examples are given to help understanding the syntax of
   the MODE command, but refer to modes defined in "Internet Relay Chat:
   Channel Management" [IRC-CHAN].

   Examples:

   MODE #Finnish +imI *!*@*.fi     ; Command to make #Finnish channel
                                   moderated and 'invite-only' with user
                                   with a hostname matching *.fi
                                   automatically invited.

   MODE #Finnish +o Kilroy         ; Command to give 'chanop' privileges
                                   to Kilroy on channel #Finnish.

   MODE #Finnish +v Wiz            ; Command to allow WiZ to speak on
                                   #Finnish.

   MODE #Fins -s                   ; Command to remove 'secret' flag
                                   from channel #Fins.

   MODE #42 +k oulu                ; Command to set the channel key to
                                   "oulu".

   MODE #42 -k oulu                ; Command to remove the "oulu"
                                   channel key on channel "#42".


   MODE #eu-opers +l 10            ; Command to set the limit for the
                                   number of users on channel
                                   "#eu-opers" to 10.

   :WiZ!jto@tolsun.oulu.fi MODE #eu-opers -l
                                   ; User "WiZ" removing the limit for
                                   the number of users on channel "#eu-
                                   opers".

   MODE &oulu +b                   ; Command to list ban masks set for
                                   the channel "&oulu".

   MODE &oulu +b *!*@*             ; Command to prevent all users from
                                   joining.

   MODE &oulu +b *!*@*.edu +e *!*@*.bu.edu
                                   ; Command to prevent any user from a
                                   hostname matching *.edu from joining,
                                   except if matching *.bu.edu

   MODE #bu +be *!*@*.edu *!*@*.bu.edu
                                   ; Comment to prevent any user from a
                                   hostname matching *.edu from joining,
                                   except if matching *.bu.edu

   MODE #meditation e              ; Command to list exception masks set
                                   for the channel "#meditation".

   MODE #meditation I              ; Command to list invitations masks
                                   set for the channel "#meditation".

   MODE !12345ircd O               ; Command to ask who the channel
                                   creator for "!12345ircd" is

4. Channel Modes

   The various modes available for channels are as follows:

    O - give "channel creator" status;
    o - give/take channel operator privilege;
    v - give/take the voice privilege;

    a - toggle the anonymous channel flag;
    i - toggle the invite-only channel flag;
    m - toggle the moderated channel;
    n - toggle the no messages to channel from clients on the
        outside;
    q - toggle the quiet channel flag;
    p - toggle the private channel flag;
    s - toggle the secret channel flag;
    r - toggle the server reop channel flag;
    t - toggle the topic settable by channel operator only flag;

    k - set/remove the channel key (password);
    l - set/remove the user limit to channel;

    b - set/remove ban mask to keep users out;
    e - set/remove an exception mask to override a ban mask;
    I - set/remove an invitation mask to automatically override
        the invite-only flag;

   Unless mentioned otherwise below, all these modes can be manipulated
   by "channel operators" by using the MODE command defined in "IRC
   Client Protocol" [IRC-CLIENT].

*/

bool isValidChanModeString(const std::string& mode_str) {
    if (mode_str.empty()) {
        return false;
    }

    size_t pos = 0;

    // Optional sign '+' or '-'
    if (mode_str[0] == '+' || mode_str[0] == '-') {
        pos++;
    } else {
        return false ;
    }

    if (pos == mode_str.length()) {
        return false ;
    } else {
        while (pos < mode_str.length()) {
            char current_char = mode_str[pos];
            if (current_char != 'O' && 
                current_char != 'o' &&
                current_char != 'v' && 
                current_char != 'a' &&
                current_char != 'i' &&
                current_char != 'm' && 
                current_char != 'n' &&
                current_char != 'q' &&
                current_char != 'p' && 
                current_char != 's' &&
                current_char != 'r' &&
                current_char != 't' && 
                current_char != 'k' &&                                                            
                current_char != 'l' &&
                current_char != 'b' && 
                current_char != 'e' &&
                current_char != 'I') {
                return false;
            }
            pos++;
        }
    }

    return true;
}

void set_chanflags (std::vector<std::string> &_tokens, size_t token, 
                    Client * client, Channel * channel, IrcMM & _mm)
{
    std::stringstream ss ;
    std::string flags = _tokens[token] ;
    size_t parametrizedflags = 0 ;
    for (size_t i = 1; i < flags.size(); i++)
    {
        std::string the_flag(1, flags[i]);
        switch (flags[i]) {
        case 'O':
            //channel->setFlagInvisible();
            client->enqueueIrcMessage(_mm.Fmt_ERR_UMODEUNTREATED(the_flag));
            break ;
        case 'o':
            //channel->setFlagWallops();
            client->enqueueIrcMessage(_mm.Fmt_ERR_UMODEUNTREATED(the_flag));            
            break ;
        case 'v':
            //channel->setFlagRestricted();
            client->enqueueIrcMessage(_mm.Fmt_ERR_UMODEUNTREATED(the_flag));
            break ;
        case 'a':
            //channel->setFlagOperator();
            client->enqueueIrcMessage(_mm.Fmt_ERR_UMODEUNTREATED(the_flag));
            break ;
        case 'i':
            channel->SetInvitOnly();
            break ;             
        case 'm':
            //channel->setFlagInvisible();
            client->enqueueIrcMessage(_mm.Fmt_ERR_UMODEUNTREATED(the_flag));
            break ;
        case 'n':
            //channel->setFlagWallops();
            client->enqueueIrcMessage(_mm.Fmt_ERR_UMODEUNTREATED(the_flag));            
            break ;
        case 'q':
            //channel->setFlagRestricted();
            client->enqueueIrcMessage(_mm.Fmt_ERR_UMODEUNTREATED(the_flag));
            break ;
        case 'p':
            //channel->setFlagOperator();
            client->enqueueIrcMessage(_mm.Fmt_ERR_UMODEUNTREATED(the_flag));
            break ;
        case 's':
            //channel->setFlagLocalOperator();
            client->enqueueIrcMessage(_mm.Fmt_ERR_UMODEUNTREATED(the_flag));
            break ;     
        case 'r':
            //channel->setFlagInvisible();
            client->enqueueIrcMessage(_mm.Fmt_ERR_UMODEUNTREATED(the_flag));
            break ;
        case 't':
            channel->SetTopicRestrict();        
            break ;
        case 'k':
            parametrizedflags += 1 ;
            channel->SetKeyRequired(_tokens[token + parametrizedflags]);
            break ;
        case 'l':
            int limit;
            parametrizedflags += 1 ;

            ss <<_tokens[token + parametrizedflags];
            if (ss >> limit) {
                channel->SetLimit(limit);
            } else {
                client->enqueueIrcMessage(
                    _mm.Fmt_ERR_UNKNOWNMODE(flags[i], channel->getName()));
            }
            ss.str("");
            ss.clear();
            break ;
        case 'b':
            //channel->setFlagLocalOperator();
            client->enqueueIrcMessage(_mm.Fmt_ERR_UMODEUNTREATED(the_flag));
            break ;
        case 'e':
            //channel->setFlagOperator();
            client->enqueueIrcMessage(_mm.Fmt_ERR_UMODEUNTREATED(the_flag));
            break ;
        case 'I':
            //channel->setFlagLocalOperator();
            client->enqueueIrcMessage(_mm.Fmt_ERR_UMODEUNTREATED(the_flag));
            break ;                  
        }
    }
}

void unset_chanflags (std::vector<std::string> & _tokens, size_t i,
                    Client * client, Channel * channel, IrcMM & _mm)
{
        std::string flags = _tokens[i] ;
        for (size_t i = 1; i < flags.size(); i++)
    {
        std::string the_flag(1, flags[i]);
        switch (flags[i]) {
        case 'O':
            //channel->setFlagInvisible();
            client->enqueueIrcMessage(_mm.Fmt_ERR_UMODEUNTREATED(the_flag));
            break ;
        case 'o':
            //channel->setFlagWallops();
            client->enqueueIrcMessage(_mm.Fmt_ERR_UMODEUNTREATED(the_flag));            
            break ;
        case 'v':
            //channel->setFlagRestricted();
            client->enqueueIrcMessage(_mm.Fmt_ERR_UMODEUNTREATED(the_flag));
            break ;
        case 'a':
            //channel->setFlagOperator();
            client->enqueueIrcMessage(_mm.Fmt_ERR_UMODEUNTREATED(the_flag));
            break ;
        case 'i':
            channel->UnsetInvitOnly();
            break ;             
        case 'm':
            //channel->setFlagInvisible();
            client->enqueueIrcMessage(_mm.Fmt_ERR_UMODEUNTREATED(the_flag));
            break ;
        case 'n':
            //channel->setFlagWallops();
            client->enqueueIrcMessage(_mm.Fmt_ERR_UMODEUNTREATED(the_flag));            
            break ;
        case 'q':
            //channel->setFlagRestricted();
            client->enqueueIrcMessage(_mm.Fmt_ERR_UMODEUNTREATED(the_flag));
            break ;
        case 'p':
            //channel->setFlagOperator();
            client->enqueueIrcMessage(_mm.Fmt_ERR_UMODEUNTREATED(the_flag));
            break ;
        case 's':
            //channel->setFlagLocalOperator();
            client->enqueueIrcMessage(_mm.Fmt_ERR_UMODEUNTREATED(the_flag));
            break ;     
        case 'r':
            //channel->setFlagInvisible();
            client->enqueueIrcMessage(_mm.Fmt_ERR_UMODEUNTREATED(the_flag));
            break ;
        case 't':
            channel->UnsetTopicRestrict();        
            break ;
        case 'k':
            channel->UnsetKeyRequired();
            break ;
        case 'l':
            channel->UnsetLimit();
            break ;
        case 'b':
            //channel->setFlagLocalOperator();
            client->enqueueIrcMessage(_mm.Fmt_ERR_UMODEUNTREATED(the_flag));
            break ;
        case 'e':
            //channel->setFlagOperator();
            client->enqueueIrcMessage(_mm.Fmt_ERR_UMODEUNTREATED(the_flag));
            break ;
        case 'I':
            //channel->setFlagLocalOperator();
            client->enqueueIrcMessage(_mm.Fmt_ERR_UMODEUNTREATED(the_flag));
            break ;                  
        }
    }
}

void Parser::_cmd_mode_channel(Client * client, ChanName & _channelname)
{
    std::stringstream msg;
    std::string _channelname_str ;
    Channel*  _channelptr;
    size_t count_plus = 0;
    size_t count_minu = 0;

    _channelptr = _server.findChannel(_channelname.get() ) ;
    if ( _channelptr == NULL ) {
        // There is not such channel.     
        client->enqueueIrcMessage(this->_mm.Fmt_ERR_NOSUCHCHANNEL(_channelname.get()));
        return ;
    }

    if (this->_tokens.size() == 2) {

        //  MODE <chan>                  ; Command to check the chan mode.
        std::string modo = _channelptr->getModes(_channelptr->isMember(client)) ;

        std::vector<std::string> parts = this->_splitString(modo, ' ');
        if (parts.size() == 1){
            client->enqueueIrcMessage(this->_mm.Fmt_RPL_CHANNELMODEIS(
                client->getNick(),                
                _channelname.get(),
                parts[0],
                ""));
            return ;
        }
        if (parts.size() == 2){
            client->enqueueIrcMessage(this->_mm.Fmt_RPL_CHANNELMODEIS(
                client->getNick(),                
                _channelname.get(),
                parts[0],
                parts[1]));
            return ;
        }

        std::string  params = parts[1] ;
        for (size_t i=2; i < parts.size(); i++) {
            params += " " + parts[i];
        }
        client->enqueueIrcMessage(this->_mm.Fmt_RPL_CHANNELMODEIS(
                client->getNick(),
                _channelname.get(),
                parts[0],
                params));
        return ;
    }        
    
    //  MODE <chan>  *( ( "-" / "+" ) *<modes> *<modeparams> ) 
    // ; Command to set/unset the chan mode.
    if (!_channelptr->isAdmin(client))
    {
        client->enqueueIrcMessage(this->_mm.Fmt_ERR_CHANOPRIVSNEEDED(
            _channelptr->getName())
        );
        return ;
    }
    for (size_t i = 2; i < this->_tokens.size() ; i++)
    {
        if ( (this->_tokens[i][0] == '+') || (this->_tokens[i][0] == '-') ) {
            if (!isValidChanModeString(this->_tokens[i])) {
                client->enqueueIrcMessage(
                    this->_mm.Fmt_ERR_UMODEUNKNOWNFLAG()) ;
                return ;
            }
            count_plus += (this->_tokens[i][0] == '+') ;
            count_minu += (this->_tokens[i][0] == '-') ;
        }
    }

    if ( (count_plus > 1) || (count_minu > 1)) {
        client->enqueueIrcMessage(
                this->_mm.Fmt_ERR_UMODEUNKNOWNFLAG()) ;
            return ;
    }

        std::string u_mode;
    for (size_t i = 2; i < this->_tokens.size() ; i++)
    {
        u_mode += this->_tokens[i];
        if (this->_tokens[i][0] == '+')
        {
            set_chanflags(this->_tokens, i, client, _channelptr, _mm);
        } else if (this->_tokens[i][0] == '-') {
            unset_chanflags(this->_tokens,i, client, _channelptr, _mm);
        }

    }
    client->setUsermode(u_mode);
    std::string modo = _channelptr->getModes(_channelptr->isMember(client)) ;

        std::vector<std::string> parts = this->_splitString(modo, ' ');
        if (parts.size() == 1){
            _channelptr->broadcastMessage(this->_mm.Fmt_RPL_CHANNELMODEIS(
                client->getNick(),                
                _channelname.get(),
                parts[0],
                ""),NULL);
            return ;
        }
        else
        {
            std::string argParts;
            for (size_t i = 1; i < parts.size(); i++)
            {
                argParts += parts[i] + " ";
            }   
            _channelptr->broadcastMessage(this->_mm.Fmt_RPL_CHANNELMODEIS(
                client->getNick(),                
                _channelname.get(),
                parts[0],
                argParts),NULL);
            return ;
        }
    return ;
}
/*
Some logs ahmed
From chanop:
<< MODE #aaa +k key
>> :user_01!user01 MODE #aaa +k ey
<< MODE #bbb +k koko
>> :user_01!user01 MODE #bbb +k oko
<< MODE #ccc +k loko
>> :user_01!user01 MODE #ccc +k loko

Seen by regular user:
>> :user_01!user01 MODE #aaa +k ey
>> :user_01!user01 MODE #bbb +k oko
>> :user_01!user01 MODE #ccc +k loko

*/