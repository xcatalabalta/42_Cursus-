#include "Parser.class.hpp"
void Parser::_cmd_quit(Client * client)
{
	client->enqueueIrcMessage(
        this->_mm.Fmt_ERR_COMMANDUNTREATED(
            client->getNick(),
            "QUIT"
        ));
    return ;
}
