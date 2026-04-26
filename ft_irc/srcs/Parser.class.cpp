#include "Parser.class.hpp"


std::string Parser::_token_pass = "PASS" ;
std::string Parser::_token_nick = "NICK" ;
std::string Parser::_token_user = "USER" ;
std::string Parser::_token_oper = "OPER" ;
std::string Parser::_token_quit = "QUIT" ;
std::string Parser::_token_pong = "PONG" ;
std::string Parser::_token_ping = "PING" ;
std::string Parser::_token_join = "JOIN" ;
std::string Parser::_token_part = "PART" ;
std::string Parser::_token_mode = "MODE" ;
std::string Parser::_token_topic = "TOPIC" ;
std::string Parser::_token_names = "NAMES" ;
std::string Parser::_token_list = "LIST" ;
std::string Parser::_token_invite = "INVITE" ;
std::string Parser::_token_kick = "KICK" ;
std::string Parser::_token_privmsg = "PRIVMSG" ;
std::string Parser::_token_notice = "NOTICE" ;
std::string Parser::_token_away = "AWAY" ;
std::string Parser::_token_who = "WHO" ;
std::string Parser::_token_whois = "WHOIS" ;
std::string Parser::_token_whowas = "WHOWAS" ;
std::string Parser::_token_lusers = "LUSERS" ;
std::string Parser::_token_version = "VERSION" ;
std::string Parser::_token_stats = "STATS" ;
std::string Parser::_token_links = "LINKS" ;
std::string Parser::_token_time = "TIME" ;
std::string Parser::_token_trace = "TRACE" ;
std::string Parser::_token_admin = "ADMIN" ;
std::string Parser::_token_info = "INFO" ;
std::string Parser::_token_servlist = "SERVLIST" ;
std::string Parser::_token_squery = "SQUERY" ;
std::string Parser::_token_motd = "MOTD" ;
std::string Parser::_token_kill = "KILL" ;
std::string Parser::_token_error = "ERROR" ;
std::string Parser::_token_rehash = "REHASH" ;
std::string Parser::_token_restart = "RESTART" ;
std::string Parser::_token_squirt = "SQUIRT" ;
std::string Parser::_token_connect = "CONNECT" ;
std::string Parser::_token_die = "DIE" ;
std::string Parser::_token_cap = "CAP" ;

IrcMM Parser::_mm =  IrcMM();

Parser::Parser( Server & server ) : _server(server) {
	std::stringstream ss ;
	ss << "Parser::Parser Created with a reference to server " << &server << std::endl;
    Logger::getInstance().log(ss.str());
}

Parser::~Parser( void )
{
    Logger::getInstance().log("Parser::Parser  Destroyed.");
}


/* Commented out cause the reference membre _server, can
   not be initialized.
Parser::Parser(const Parser & other)
{
    *this = other;
}


Parser & Parser::operator=(Parser const & other)
{
    this->_tokens = other._tokens ;
    this->_txt_line = other._txt_line;
    this->_command = other._command ;
    return *this ; 
}
*/
void Parser::parse(Client* client, const std::string & text_line) {
    this->_txt_line = this->_trim(text_line);
    this->_tokens.clear();
    this->_split_tokens();
    this->_backbone(client) ; 
}
// Elimina espacios, tabuladores, retornos de carro (\r) y saltos de línea (\n) al inicio y final de un string.
//Sirve para limpiar args, ya que en IRC suelen llegar con saltos de línea.
std::string Parser::_trim(const std::string& s) {
    size_t start = s.find_first_not_of(" \r\n\t");
    size_t end   = s.find_last_not_of(" \r\n\t");
    if (start == std::string::npos) return "";
    return s.substr(start, end - start + 1);
}

// Helper function to split a string by a delimiter
std::vector<std::string> Parser::_splitString(const std::string& s, char delimiter) {
    std::vector<std::string> parts;
    std::string part;
    std::istringstream stream(s);
    while (std::getline(stream, part, delimiter)) {
        parts.push_back(part);
    }
    return parts;
}
/* I will call it to reprocess some tokens. 
Original tokens: JOIN #foo,#bar fubar,foobar 
Modified tokens: JOIN #foo #bar fubar foobar 
*/
void Parser::_processTokens(std::vector<std::string>& _tokens) {
    // We use a forward loop, but manage the index carefully as we modify the vector
    for (size_t i = 0; i < _tokens.size(); ) {
        if (_tokens[i].find(',') != std::string::npos) {
            std::vector<std::string> new_parts = this->_splitString(_tokens[i], ',');

            // Replace the current token with the new parts
            _tokens.erase(_tokens.begin() + i);
            _tokens.insert(_tokens.begin() + i, new_parts.begin(), new_parts.end());
            
            // Advance the index by the number of new parts to avoid re-processing
            i += new_parts.size();
        } else {
            // Move to the next token if no comma is found
            i++;
        }
    }
}

void Parser::_split_tokens()
{
    // Create a stringstream from the phrase
    std::stringstream ss(this->_txt_line);
    std::string token;
    
    // Read tokens separated by whitespace
    while (ss >> token) {
        this->_tokens.push_back(token);
    }
    token = this->_tokens[0];
    for (size_t i = 0; i < token.size() ; i++)
        token[i] = toupper(token[i]);
    this->_command = token;
}

size_t Parser::get_num_tokens() const
{
    return this->_tokens.size() ;
}

void Parser::_backbone(Client *client)
{
    if (this->_command ==  this->_token_cap) {this->_cmd_cap(client);}
    else if (this->_command ==  this->_token_pass) {this->_cmd_pass(client);}
    else if (this->_command ==  this->_token_nick) {this->_cmd_nick(client);}
    else if (this->_command ==  this->_token_user) {this->_cmd_user(client);}
    else if (this->_command ==  this->_token_oper) {this->_cmd_oper(client);}
    else if (this->_command ==  this->_token_quit) {this->_cmd_quit(client);}
    else if (this->_command ==  this->_token_pong) {this->_cmd_pong(client);}
    else if (this->_command ==  this->_token_ping) {this->_cmd_ping(client);}
    else if (this->_command ==  this->_token_join) {this->_cmd_join(client);}
    else if (this->_command ==  this->_token_part) {this->_cmd_part(client);}
    else if (this->_command ==  this->_token_mode) {this->_cmd_mode(client);}
    else if (this->_command ==  this->_token_topic) {this->_cmd_topic(client);}
    else if (this->_command ==  this->_token_names) {this->_cmd_names(client);}
    else if (this->_command ==  this->_token_list) {this->_cmd_list(client);}
    else if (this->_command ==  this->_token_invite) {this->_cmd_invite(client);}
    else if (this->_command ==  this->_token_kick) {this->_cmd_kick(client);}
    else if (this->_command ==  this->_token_privmsg) {this->_cmd_privmsg(client);}
    else if (this->_command ==  this->_token_notice) {this->_cmd_notice(client);}
    else if (this->_command ==  this->_token_away) {this->_cmd_away(client);}
    else if (this->_command ==  this->_token_who) {this->_cmd_who(client);}
    else if (this->_command ==  this->_token_whois) {this->_cmd_whois(client);}
    else if (this->_command ==  this->_token_whowas) {this->_cmd_whowas(client);}
    else if (this->_command ==  this->_token_lusers) {this->_cmd_lusers(client);}
    else if (this->_command ==  this->_token_version) {this->_cmd_version(client);}
    else if (this->_command ==  this->_token_stats) {this->_cmd_stats(client);}
    else if (this->_command ==  this->_token_links) {this->_cmd_links(client);}
    else if (this->_command ==  this->_token_time) {this->_cmd_time(client);}
    else if (this->_command ==  this->_token_trace) {this->_cmd_trace(client);}
    else if (this->_command ==  this->_token_admin) {this->_cmd_admin(client);}
    else if (this->_command ==  this->_token_info) {this->_cmd_info(client);}
    else if (this->_command ==  this->_token_servlist) {this->_cmd_servlist(client);}
    else if (this->_command ==  this->_token_squery) {this->_cmd_squery(client);}
    else if (this->_command ==  this->_token_motd) {this->_cmd_motd(client);}
    else if (this->_command ==  this->_token_kill) {this->_cmd_kill(client);}
    else if (this->_command ==  this->_token_error) {this->_cmd_error(client);}
    else if (this->_command ==  this->_token_rehash) {this->_cmd_rehash(client);}
    else if (this->_command ==  this->_token_restart) {this->_cmd_restart(client);}
    else if (this->_command ==  this->_token_squirt) {this->_cmd_squirt(client);}
    else if (this->_command ==  this->_token_connect) {this->_cmd_connect(client);}
    else if (this->_command ==  this->_token_die) {this->_cmd_die(client);}
    else if (this->_command ==  this->_token_cap) {this->_cmd_cap(client);}
    else {
        std::string msg = this->_mm.Fmt_ERR_UNKNOWNCOMMAND(this->_command) ;
		Logger::getInstance().log(msg);
        this->_error = ERR_UNKNOWNCOMMAND ;
        client->enqueueIrcMessage(msg);
    }
}
