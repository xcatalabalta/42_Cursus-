#ifndef PARSER_CLASS_H
#define PARSER_CLASS_H

#include <string.h>
#include <iostream>
#include <string>
#include <vector>
#include <ostream>
#include <sstream>
#include "IrcNumerics.hpp"
#include "IrcMM.class.hpp"
#include "NickName.class.hpp"
#include "ChanName.class.hpp"
#include "Channel.class.hpp"
#include "Logger.class.hpp"
#include "Parser.class.hpp"
#include "Server.hpp"
#include "Client.hpp"


// Forward declaration
class Server;

class Parser
{
    private:
    Server& _server; // referencia al servidor (no se reasigna)
    // Disabling the canonical copy methods in C++98
    // Declare but do NOT define these methods
    Parser(const Parser & other);
    Parser & operator=(Parser const & other);

    static IrcMM _mm ;
    std::vector<std::string> _tokens ;
    std::string _txt_line ;
    std::string _command ; // to speed backbone funtions
    size_t _error;

	std::string _trim(const std::string& s);
    std::vector<std::string> _splitString(const std::string& s, char delimiter);
    void _processTokens(std::vector<std::string>& _tokens) ;
    void _split_tokens();
    void _backbone(Client * client) ;
    void _cmd_pass(Client * client) ;
    void _cmd_nick(Client * client) ;
    void _cmd_user(Client * client) ;
    void _cmd_oper(Client * client) ;
    void _cmd_quit(Client * client) ;
    void _cmd_pong(Client * client) ;
    void _cmd_ping(Client * client) ;
    void _cmd_join(Client * client) ;
    void _cmd_part(Client * client) ;
    void _cmd_mode(Client * client) ;
    void _cmd_mode_user(Client * client, NickName & _nick) ;
    void _cmd_mode_channel(Client * client, ChanName & _channelname) ;   
    void _cmd_topic(Client * client) ;
    void _cmd_names(Client * client) ;
    void _cmd_list(Client * client) ;
    void _cmd_invite(Client * client) ;
    void _cmd_kick(Client * client) ;
    void _cmd_privmsg(Client * client) ;
    void _cmd_privmsg_user(Client * client, NickName & _nick) ;
    void _cmd_privmsg_channel(Client * client, ChanName & _channelname) ;
    void _cmd_notice(Client * client) ;
    void _cmd_notice_user(Client * client, NickName & _nick);
    void _cmd_notice_channel(Client * client, ChanName & _channelname);
    void _cmd_away(Client * client) ;
    void _cmd_who(Client * client) ;
    void _cmd_whois(Client * client) ;
    void _cmd_whowas(Client * client) ;
    void _cmd_lusers(Client * client) ;
    void _cmd_version(Client * client) ;
    void _cmd_stats(Client * client) ;
    void _cmd_links(Client * client) ;
    void _cmd_time(Client * client) ;
    void _cmd_trace(Client * client) ;
    void _cmd_admin(Client * client) ;
    void _cmd_info(Client * client) ;
    void _cmd_servlist(Client * client) ;
    void _cmd_squery(Client * client) ;
    void _cmd_motd(Client * client) ;
    void _cmd_kill(Client * client) ;
    void _cmd_error(Client * client) ;
    void _cmd_rehash(Client * client) ;
    void _cmd_restart(Client * client) ;
    void _cmd_squirt(Client * client) ;
    void _cmd_connect(Client * client) ;
    void _cmd_die(Client * client) ;
    void _cmd_cap(Client * client) ;
    
    static std::string _token_pass ;
    static std::string _token_nick ;
    static std::string _token_user ;
    static std::string _token_oper ;
    static std::string _token_quit ;
    static std::string _token_pong ;
    static std::string _token_ping ;
    static std::string _token_join ;
    static std::string _token_part ;
    static std::string _token_mode ;
    static std::string _token_topic ;
    static std::string _token_names ;
    static std::string _token_list ;
    static std::string _token_invite ;
    static std::string _token_kick ;
    static std::string _token_privmsg ;
    static std::string _token_notice ;
    static std::string _token_away ;
    static std::string _token_who ;
    static std::string _token_whois  ;
    static std::string _token_whowas ;
    static std::string _token_lusers ;
    static std::string _token_version;
    static std::string _token_stats  ;
    static std::string _token_links  ;
    static std::string _token_time ;
    static std::string _token_trace  ;
    static std::string _token_admin  ;
    static std::string _token_info ;
    static std::string _token_servlist ;
    static std::string _token_squery ;
    static std::string _token_motd ;
    static std::string _token_kill ;
    static std::string _token_error  ;
    static std::string _token_rehash ;
    static std::string _token_restart ;
    static std::string _token_squirt ;
    static std::string _token_connect ;
    static std::string _token_die ;
    static std::string _token_cap ;

    public:
        Parser(Server & server);
        ~Parser();
    
		// Punto de entrada: recibe una línea completa desde el cliente
        void parse(Client* client, const std::string& line);

        size_t get_num_tokens() const;
        

};

#endif
