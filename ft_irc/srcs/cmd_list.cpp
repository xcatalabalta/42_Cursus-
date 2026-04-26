#include "Parser.class.hpp"
/*
3.2.6 List message

      Command: LIST
   Parameters: [ <channel> *( "," <channel> ) [ <target> ] ]

   The list command is used to list channels and their topics.  If the
   <channel> parameter is used, only the status of that channel is
   displayed.

   If the <target> parameter is specified, the request is forwarded to
   that server which will generate the reply.

   Wildcards are allowed in the <target> parameter.

   Numeric Replies:

           ERR_TOOMANYMATCHES              ERR_NOSUCHSERVER
           RPL_LIST                        RPL_LISTEND

   Examples:

   LIST                            ; Command to list all channels.

   LIST #twilight_zone,#42         ; Command to list channels
                                   #twilight_zone and #42*/
void Parser::_cmd_list(Client * client)
{

    if (!client->isRegistered()) {
        client->enqueueIrcMessage(this->_mm.Fmt_ERR_NOTREGISTERED ());
        return ;
    }
    if (this->_tokens.size() == 1) {
        // Client & cliref = *client ;
        // _server.listAllChannels(cliref) ;
        _server.listChannels(client) ;
        return ;
    }
    if (this->_tokens.size() >= 2) {
        std::vector<std::string> lista_canales = this->_splitString(this->_tokens[1], ',') ;
        for (size_t i = 0; i < lista_canales.size() ; i++) {}
    }
    //_server.listChannels(client) ;
    return ;
}
