#include "Parser.class.hpp"
void Parser::_cmd_squery(Client * client)
{
	client->enqueueIrcMessage(
        this->_mm.Fmt_ERR_COMMANDUNTREATED(
            client->getNick(),
            "SQUERY"
        ));
    return ;
}
