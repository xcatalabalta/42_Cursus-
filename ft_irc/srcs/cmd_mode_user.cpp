#include "Parser.class.hpp"
/*
3.1.5 User mode message

      Command: MODE
   Parameters: <nickname>
               *( ( "+" / "-" ) *( "i" / "w" / "o" / "O" / "r" ) )

   The user MODE's are typically changes which affect either how the
   client is seen by others or what 'extra' messages the client is sent.

   A user MODE command MUST only be accepted if both the sender of the
   message and the nickname given as a parameter are both the same.  If
   no other parameter is given, then the server will return the current
   settings for the nick.

      The available modes are as follows:

           a - user is flagged as away;
           i - marks a users as invisible;
           w - user receives wallops;
           r - restricted user connection;
           o - operator flag;
           O - local operator flag;
           s - marks a user for receipt of server notices.

   Additional modes may be available later on.

   The flag 'a' SHALL NOT be toggled by the user using the MODE command,
   instead use of the AWAY command is REQUIRED.

   If a user attempts to make themselves an operator using the "+o" or
   "+O" flag, the attempt SHOULD be ignored as users could bypass the
   authentication mechanisms of the OPER command.  There is no
   restriction, however, on anyone `deopping' themselves (using "-o" or
   "-O").

   On the other hand, if a user attempts to make themselves unrestricted
   using the "-r" flag, the attempt SHOULD be ignored.  There is no
   restriction, however, on anyone `deopping' themselves (using "+r").
   This flag is typically set by the server upon connection for
   administrative reasons.  While the restrictions imposed are left up
   to the implementation, it is typical that a restricted user not be
   allowed to change nicknames, nor make use of the channel operator
   status on channels.

   The flag 's' is obsolete but MAY still be used.

   Numeric Replies:

           ERR_NEEDMOREPARAMS              ERR_USERSDONTMATCH OK
           ERR_UMODEUNKNOWNFLAG            RPL_UMODEIS OK

   Examples:

   MODE WiZ -w                     ; Command by WiZ to turn off
                                   reception of WALLOPS messages.

   MODE Angel +i                   ; Command from Angel to make herself
                                   invisible.

   MODE WiZ -o                     ; WiZ 'deopping' (removing operator
                                   status).
*/

bool isValidUserModeString(const std::string& mode_str) {
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

    // Zero or more mode characters 'i', 'w', 'o', 'O', 'r'
    if (pos == mode_str.length()) {
        return false ;
    } else {
        while (pos < mode_str.length()) {
            char current_char = mode_str[pos];
            if (current_char != 'i' && current_char != 'w' &&
                current_char != 'o' && current_char != 'O' &&
                current_char != 'r') {
                return false;
            }
            pos++;
        }
    }

    return true;
}
//characters 'i', 'w', 'o', 'O', 'r'

//    i - marks a users as invisible;
//    w - user receives wallops;
//    r - restricted user connection;
//    o - operator flag;
//    O - local operator flag;
void set_userflags (std::string & flags, Client * client, IrcMM & _mm)
{
    for (size_t i = 1; i < flags.size(); i++)
    {
        std::string the_flag(1, flags[i]);
        switch (flags[i]) {
        case 'i':
            //client->setFlagInvisible();
            client->enqueueIrcMessage(_mm.Fmt_ERR_UMODEUNTREATED(the_flag));
            break ;
        case 'w':
            //client->setFlagWallops();
            client->enqueueIrcMessage(_mm.Fmt_ERR_UMODEUNTREATED(the_flag));            
            break ;
        case 'r':
            //client->setFlagRestricted();
            client->enqueueIrcMessage(_mm.Fmt_ERR_UMODEUNTREATED(the_flag));
            break ;
        case 'o':
            //client->setFlagOperator();
            client->enqueueIrcMessage(_mm.Fmt_ERR_UMODEUNTREATED(the_flag));
            break ;
        case 'O':
            //client->setFlagLocalOperator();
            client->enqueueIrcMessage(_mm.Fmt_ERR_UMODEUNTREATED(the_flag));
            break ;                                                
        }
    }
}

void unset_userflags (std::string & flags, Client * client, IrcMM & _mm)
{
    for (size_t i = 1; i < flags.size(); i++)
    {
        std::string the_flag(1, flags[i]);
        switch (flags[i]) {
        case 'i':
            //client->unsetFlagInvisible();
            client->enqueueIrcMessage(_mm.Fmt_ERR_UMODEUNTREATED(the_flag));
            break ;
        case 'w':
            //client->unsetFlagWallops();
            client->enqueueIrcMessage(_mm.Fmt_ERR_UMODEUNTREATED(the_flag));            
            break ;
        case 'r':
            //client->unsetFlagRestricted();
            client->enqueueIrcMessage(_mm.Fmt_ERR_UMODEUNTREATED(the_flag));
            break ;
        case 'o':
            //client->unsetFlagOperator();
            client->enqueueIrcMessage(_mm.Fmt_ERR_UMODEUNTREATED(the_flag));
            break ;
        case 'O':
            //client->unsetFlagLocalOperator();
            client->enqueueIrcMessage(_mm.Fmt_ERR_UMODEUNTREATED(the_flag));
            break ;                                                
        }
    }
}

void Parser::_cmd_mode_user(Client * client, NickName & _nick)
{
    size_t count_plus = 0;
    size_t count_minu = 0;
    
   
    if (client->getNick() != _nick.get()) {
        client->enqueueIrcMessage(this->_mm.Fmt_ERR_USERSDONTMATCH());
        return ;
    }
    // MODE <nick>                 ; shows user mode
    if (this->_tokens.size() == 2) {
        client->enqueueIrcMessage(
            this->_mm.Fmt_RPL_UMODEIS(client->getUsermode()) );
        return ;
    }
    for (size_t i = 2; i < this->_tokens.size() ; i++)
    {
        if (!isValidUserModeString(this->_tokens[i])) {
            client->enqueueIrcMessage(
                this->_mm.Fmt_ERR_UMODEUNKNOWNFLAG()) ;
            return ;
        } else {
            count_plus += (this->_tokens[i][0] == '+') ;
            count_minu += (this->_tokens[i][0] == '-') ;
        }
    }

    if ( (count_plus > 1) || (count_minu > 1)) {
        client->enqueueIrcMessage(
                this->_mm.Fmt_ERR_UMODEUNKNOWNFLAG()) ;
            return ;
    }
    // MODE <nick>  <flags>               ; shows user mode
    std::string u_mode;
    for (size_t i = 2; i < this->_tokens.size() ; i++)
    {
        u_mode += this->_tokens[i];
        if (this->_tokens[i][0] == '+')
        {
            set_userflags(this->_tokens[i], client, _mm);
        } else {
            unset_userflags(this->_tokens[i], client,_mm);
        }
    }
    client->setUsermode(u_mode);
}

