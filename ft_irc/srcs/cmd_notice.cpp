#include "Parser.class.hpp"
/*
void Parser::_cmd_notice(Client * client)
{
	client->enqueueIrcMessage(
        this->_mm.Fmt_ERR_COMMANDUNTREATED(
            client->getNick(),
            "NOTICE"
        ));
    return ;
}
*/
void Parser::_cmd_notice(Client * client)
{
    if (!client->isRegistered()) {
        // NOTICE should not generate error replies
        return;
    }
    
    if (this->_tokens.size() < 3) {
        // NOTICE should not generate error replies
        return;
    }
    
    // NOTICE <user/channel> <text to be sent>
    try {
        // Try as nickname first
        NickName _nick(this->_tokens[1]);
        _cmd_notice_user(client, _nick);
    } catch (const std::exception& e) {
        try {
            // Try as channel name
            ChanName _channelname(this->_tokens[1]);
            _cmd_notice_channel(client, _channelname);
        } catch (const std::exception& e) {
            // NOTICE should not generate error replies
            // Silently fail
        }
    }
}

void Parser::_cmd_notice_user(Client * client, NickName & _nick)
{
    Client * client_to_notify = _server.findNick(_nick);
    
    if (client_to_notify == NULL) {
        // NOTICE does NOT send ERR_NOSUCHNICK
        // Silently fail
        return;
    }
    
    // Build message text
    std::string mensa = this->_tokens[2];
    if (!mensa.empty() && mensa[0] == ':') {
        mensa.erase(mensa.begin());
    }
    
    for (size_t i = 3; i < this->_tokens.size(); ++i) {
        mensa = mensa + " " + this->_tokens[i];
    }
    
    // Format NOTICE message
    std::string noticeMsg = ":" + client->getNick() + "!" + 
                           client->getUser() + "@" + client->getHost() + 
                           " NOTICE " + _nick.get() + " :" + mensa;
    
    client_to_notify->enqueueIrcMessage(noticeMsg);
}

void Parser::_cmd_notice_channel(Client * client, ChanName & _channelname)
{
    Channel* canal = _server.findChannel(_channelname.get());
    
    if (canal == NULL) {
        // NOTICE does NOT send ERR_NOSUCHCHANNEL
        // Silently fail
        return;
    }
    
    if (!canal->isMember(client)) {
        // NOTICE does NOT send ERR_CANNOTSENDTOCHAN
        // Silently fail
        return;
    }
    
    // Build message text
    std::string mensa = this->_tokens[2];
    if (!mensa.empty() && mensa[0] == ':') {
        mensa.erase(mensa.begin());
    }
    
    for (size_t i = 3; i < this->_tokens.size(); ++i) {
        mensa = mensa + " " + this->_tokens[i];
    }
    
    // Format NOTICE message
    std::string noticeMsg = ":" + client->getNick() + "!" + 
                           client->getUser() + "@" + client->getHost() + 
                           " NOTICE " + _channelname.get() + " :" + mensa;
    
    canal->broadcastMessage(noticeMsg, client);
}
