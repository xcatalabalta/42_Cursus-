#include "Parser.class.hpp"
void Parser::_cmd_oper(Client * client)
{
	client->enqueueIrcMessage(
        this->_mm.Fmt_ERR_COMMANDUNTREATED(
            client->getNick(),
            "OPER"
        ));
    return ;
}
