#include "Parser.class.hpp"
void Parser::_cmd_links(Client * client)
{
	client->enqueueIrcMessage(
        this->_mm.Fmt_ERR_COMMANDUNTREATED(
            client->getNick(),
            "LINKS"
        ));
    return ;
}
