#include "Parser.class.hpp"
void Parser::_cmd_die(Client * client)
{
	client->enqueueIrcMessage(
        this->_mm.Fmt_ERR_COMMANDUNTREATED(
            client->getNick(),
            "DIE"
        ));
    return ;
}
