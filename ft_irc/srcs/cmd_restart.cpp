#include "Parser.class.hpp"
void Parser::_cmd_restart(Client * client)
{
	client->enqueueIrcMessage(
        this->_mm.Fmt_ERR_COMMANDUNTREATED(
            client->getNick(),
            "RESTART"
        ));
    return ;
}
