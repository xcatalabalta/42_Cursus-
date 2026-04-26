#include "Parser.class.hpp"
void Parser::_cmd_error(Client * client)
{
	client->enqueueIrcMessage(
        this->_mm.Fmt_ERR_COMMANDUNTREATED(
            client->getNick(),
            "ERROR"
        ));
    return ;
}
