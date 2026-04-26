#include "Parser.class.hpp"

void Parser::_cmd_admin(Client * client)
{
	client->enqueueIrcMessage(
        this->_mm.Fmt_ERR_COMMANDUNTREATED(
            client->getNick(),
            "ADMIN"
        ));
    return ;
}
