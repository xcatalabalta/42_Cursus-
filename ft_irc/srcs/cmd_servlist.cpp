#include "Parser.class.hpp"
void Parser::_cmd_servlist(Client * client)
{
	client->enqueueIrcMessage(
        this->_mm.Fmt_ERR_COMMANDUNTREATED(
            client->getNick(),
            "SERVLIST"
        ));
    return ;
}
