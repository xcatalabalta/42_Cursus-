#ifndef IRCMESSAGEMANAGER_HPP
#define IRCMESSAGEMANAGER_HPP

#include "NickName.class.hpp"
#include "HostName.class.hpp"
#include "UserName.class.hpp"
#include "ChanName.class.hpp"
#include "IrcNumerics.hpp"
#include <string>
#include <map>
#include <stdexcept>
#include <sstream>
#include <iostream>
#include <ctime> 

// Clase para gestionar los mensajes de IRC
class IrcMM {
public:
    // Constructor que inicializa el mapa con todos los mensajes
    IrcMM( void );
    // Constructor por copia
    IrcMM( IrcMM const & other) ;
    // Operador de assignacion
    IrcMM & operator=(IrcMM const & other);
    // Destructor
    ~IrcMM( void ) ;

    // 001 RPL_WELCOME 
    std::string Fmt_RPL_WELCOME (
        const std::string   & nick, 
        const std::string   & user, 
        const std::string   & host ) ;
    // 002 RPL_YOURHOST, "Your host is <servername>, running version <ver>    ))
    std::string Fmt_RPL_YOURHOST (
        const std::string   & server, 
        const std::string   & version ) ;     
    // 003 RPL_CREATED, "This server was created <date>                       ))
    std::string Fmt_RPL_CREATED (
        const time_t         & time ) ;
    // 004 RPL_MYINFO, "<servername> <version> <available user modes> 
    //                                         "<available channel modes>     ))
    std::string Fmt_RPL_MYINFO (
        const std::string   & server, 
        const std::string   & version, 
        const std::string   & u_modes, 
        const std::string   & c_modes ) ;
    // 005 RPL_BOUNCE, "Try server <server name>, port <port number>          ))
    std::string Fmt_RRPL_BOUNCE (
        const std::string   & server, 
        const int           & port_number ) ;   
    // 200 RPL_TRACELINK, "Link <version & debug level> 
    //          <destination> <next server> V<protocol version> 
    //      <link uptime in seconds> <backstream sendq> <upstream sendq>"     ))
    std::string Fmt_RPL_TRACELINK (
        const std::string   & ver, 
        const std::string   & debug, 
        const std::string   & destination, 
        const std::string   & next_server , 
        const std::string   & version, 
        const int           & uptime, 
        const int           & bs_q_size, 
        const int           & us_q_size) ;
    // 201 RPL_TRACECONNECTING, "Try. <class> <server>                        ))
    std::string Fmt_RPL_TRACECONNECTING (
        const char          & clase, 
        const std::string   & server ) ;     
    // 202 RPL_TRACEHANDSHAKE, "H.S. <class> <server>                         ))
    std::string Fmt_RPL_TRACEHANDSHAKE (
        const char          & clase, 
        const std::string   & server ) ;   
    // 203 RPL_TRACEUNKNOWN, "???? <class> [<client IP address in dot form>]  ))
    std::string Fmt_RPL_TRACEUNKNOWN (
        const char          & clase, 
        const std::string   & ip ) ;  
    // 204 RPL_TRACEOPERATOR,        "Oper <class> <nick>                     ))
    std::string Fmt_RPL_TRACEOPERATOR (
        const char          & clase, 
        const std::string   & nick ) ;  
    // 205 RPL_TRACEUSER,        "User <class> <nick>                         ))
    std::string Fmt_RPL_TRACEUSER (
        const char          & clase,
        const std::string   & nick ) ;  
    // 206 RPL_TRACESERVER, "Serv <class> <int>S 
    //      <int>C <server>   
    //      "<nick!user|*!*>@<host|server> V<protocol version>                ))
    std::string Fmt_RPL_TRACESERVER (
        const char          & clase,
        const int           & servidores_conectados, 
        const int           & clientes_conectados,
        const std::string   & host_local, 
        const std::string   & user,
        const std::string   & host_remoto,
        const std::string   & version) ;
    // 207 RPL_TRACERVICE,      "Service <class> <name> <type> <active type   ))
    std::string Fmt_RPL_RPL_TRACERVICE (
        const char          & clase, 
        const std::string   & name,
        const std::string   & type, 
        const std::string   & server ) ;  
    // 208 RPL_TRACENEWTYPE,        "<newtype> 0 <client name>                ))
    std::string Fmt_RPL_TRACENEWTYPE (
        const std::string   & type,
        const std::string   & user ) ;  
    // 209 RPL_TRACECLASS,        "Class <class> <count>                      ))
    std::string Fmt_RPL_TRACECLASS (
        const char          & clase, 
        const int           & count) ;  
    // 210 RPL_TRACERECONNECT, "Unused.                                       ))
    std::string Fmt_RPL_TRACERECONNECT () ;
    // 211 RPL_STATSLINKINFO, "<linkname> <sendq> <sent messages> <sent Kbytes> 
    //                 "<received messages> <received Kbytes> <time open>     ))
    std::string Fmt_RPL_STATSLINKINFO (
        const std::string   & link, 
        const int           & size,
        const int           & s_msg,
        const int           & s_Kbytes, 
        const int           & r_msg, 
        const int           & r_Kbytes, 
        const int           & seconds) ;    
    // 212 RPL_STATSCOMMANDS,  "<command> <count> <byte count> <remote count> ))
    std::string Fmt_RPL_STATSCOMMANDS (
        const std::string   & command, 
        const int           & count, 
        const int           & byte_count, 
        const int           & remote_count ) ;  
    // 219 RPL_ENDOFSTATS,        "<stats letter> :End of STATS report        ))
    std::string Fmt_RPL_ENDOFSTATS (
        const char          & letter ) ;
    // 221 RPL_UMODEIS,        "<user mode string>                            ))
    std::string Fmt_RPL_UMODEIS (
        const std::string   & u_mode) ;
    // 234 RPL_SERVLIST, "<name> <server> <mask> <type> <hopcount> <info>     ))
    std::string Fmt_RPL_SERVLIST (
        const std::string   & nick, 
        const std::string   & host, 
        const std::string   & mask, 
        const std::string   & type, 
        const int           & hopcount, 
        const std::string   & server_info ) ;
    // 235 RPL_SERVLISTEND,        "<mask> <type> :End of service listing     ))
    std::string Fmt_RPL_SERVLISTEND (
        const std::string   & mask,
        const std::string   & type ) ;  
    // 242 RPL_STATSUPTIME, ":Server Up %d days %d:%02d:%02d                  ))
    std::string Fmt_RPL_STATSUPTIME () ;
    // 251 RPL_LUSERCLIENT, ":There are <integer> users and <integer> 
    //                                    services on "<integer> servers      ))
    std::string Fmt_RPL_LUSERCLIENT (
        const int           & clients,
        const int           & services, 
        const int           & servers ) ;    
    // 252 RPL_LUSEROP, "<integer> :operator(s) online                        ))
    std::string Fmt_RPL_LUSEROP (
        const int           & operators ) ;
    // 253 RPL_LUSERUNKNOWN, "<integer> :unknown connection(s)                ))
    std::string Fmt_RPL_LUSERUNKNOWN (
        const int           & connections) ;    
    // 254 RPL_LUSERCHANNELS, "<integer> :channels formed                     ))
    std::string Fmt_RPL_LUSERCHANNELS (
        const int           & channels ) ;    
    // 255 RPL_LUSERME, ":I have <integer> clients and <integer> servers      ))
    std::string Fmt_RPL_LUSERME (
        const int           & clients, 
        const int           & servers ) ;     
    // 256 RPL_ADMINME, "<server> :Administrative info                        ))
    std::string Fmt_RPL_ADMINME (
        const std::string   & host) ;
    // 257 RPL_ADMINLOC1,        ":<admin info>                               ))
    std::string Fmt_RPL_ADMINLOC1 (
        const std::string   & admin_info ) ;
    // 258 RPL_ADMINLOC2,        ":<admin info>                               ))
    std::string Fmt_RPL_ADMINLOC2 (
        const std::string   & admin_info) ;
    // 259 RPL_ADMINEMAIL,        ":<admin info>                              ))
    std::string Fmt_RPL_ADMINEMAIL (
        const std::string   & admin_info ) ;
    // 261 RPL_TRACELOG,        "File <logfile> <debug level>                 ))
    std::string Fmt_RPL_TRACELOG (
        const std::string   & logfile, 
        const std::string   & debug );  
    // 262 RPL_TRACEEND, "<server name> <version & debug level> :End of TRACE ))
    std::string Fmt_RPL_TRACEEND (
        const std::string   & host,
        const std::string   & ver, 
        const std::string   & debug) ;
    // 263 RPL_TRYAGAIN,       "<command> :Please wait a while and try again. ))
    std::string Fmt_RPL_TRYAGAIN (
        const std::string   & command ) ;
    // 301 RPL_AWAY,        "<nick> :<away message>                           ))
    std::string Fmt_RPL_AWAY (
        const std::string   & nick, 
        const std::string   & message ) ; 
    // 302 RPL_USERHOST,        ":*1<reply> *( \" \" <reply> )                ))
    std::string Fmt_RPL_USERHOST (
        const std::string   & reply ) ;
    // 303 RPL_ISON, ":*1<nick> *( \" \" <nick> )                             ))
    std::string Fmt_RPL_ISON (
        const std::string   & nick ) ;
    // 305 RPL_UNAWAY, ":You are no longer marked as being away               ))
    std::string Fmt_RPL_UNAWAY () ;
    // 306 RPL_NOWAWAY, ":You have been marked as being away                  ))
    std::string Fmt_RPL_NOWAWAY () ;    
    // 311 RPL_WHOWISUSER
    std::string Fmt_RPL_WHOISUSER (
        const std::string   & nick, 
        const std::string   & user, 
        const std::string   & host, 
        const std::string   & real_name ) ;
    // 312 RPL_WHOISSERVER, "<nick> <server> :<server info>                   ))
    std::string Fmt_RPL_WHOISSERVER (
        const std::string   & nick, 
        const std::string   & host, 
        const std::string   & server_info ) ;   
    // 313 RPL_WHOISOPERATOR, "<nick> :is an IRC operator                     ))
    std::string Fmt_RPL_WHOISOPERATOR (
        const std::string   & nick ) ;
    // 314 RPL_WHOWASUSER
    std::string Fmt_RPL_WHOWASUSER (
        const std::string   & nick, 
        const std::string   & user, 
        const std::string   & host, 
        const std::string   & real_name ) ;
    // 315 RPL_ENDOFWHO,        "<name> :End of WHO list                      ))
    std::string Fmt_RPL_ENDOFWHO (
        const std::string   &  nick,
        const std::string   &  chan ) ;
    // 317 RPL_WHOISIDLE, "<nick> <integer> :seconds idle                     ))
    std::string Fmt_RPL_WHOISIDLE (
        const std::string   & nick, 
        const int   & seconds ) ;     
    // 318 RPL_ENDOFWHOIS, "<nick> :End of WHOIS list                         ))
    std::string Fmt_RPL_ENDOFWHOIS (
        const std::string   & nick ) ;
    // 319 RPL_WHOISCHANNELS, " <nick> :*( ( \"@\" / \"+\" ) <channel> \" \" )))
    std::string Fmt_RPL_WHOISCHANNELS (
        const std::string   & nick, 
        const std::string   & chan ) ;
    // 321 RPL_LISTSTART, "Obsolete.                                          ))
    std::string Fmt_RPL_LISTSTART() ;
    // 322 RPL_LIST,        "<nick> <channel> <# visible> :<topic>            ))
    std::string Fmt_RPL_LIST (
        const std::string   & nick,         
        const std::string   & chan, 
        const int           & u_visibles, 
        const std::string   & topic) ;
    // 323 RPL_LISTEND, ":End of LIST                                         ))
    std::string Fmt_RPL_LISTEND (
        const std::string   & nick        
    ) ;    
    // 324 RPL_CHANNELMODEIS, "<nick> <channel> <mode> <mode params>          ))
    std::string Fmt_RPL_CHANNELMODEIS (
        const std::string   & nick,    
        const std::string   & chan, 
        const std::string   & c_modes, 
        const std::string   & parametros ) ;
    // 325 RPL_UNIQOPIS, "<channel> <nickname>                                ))
    std::string Fmt_RPL_UNIQOPIS (
        const std::string   & chan, 
        const std::string   & nick ) ;
    // 331 RPL_NOTOPIC, "<channel> :No topic is set                           ))
    std::string Fmt_RPL_NOTOPIC (
        const std::string   & channel ) ;
    // 332 RPL_TOPIC,        "<nick> <channel> :<topic>                       ))
    std::string Fmt_RPL_TOPIC (
        const std::string   & nick,
        const std::string   & channel, 
        const std::string   & topic ) ;
    // 333 RPL_JOIN,                    ":<nick>!<user>@<host> JOIN:<channel>"))
    std::string Fmt_RPL_JOIN (
        const std::string   & nick,    
        const std::string   & user,
        const std::string   & host,     
        const std::string   & channel) ;
    // 340 RPL_INVITED, 
    //                ":<hostnick>!<user>@<host> INVITE <guestnick> :<channel>))
    std::string Fmt_RPL_INVITED (
        const std::string   & hostnick,
        const std::string   & user,
        const std::string   & host,        
        const std::string   & guestnick,
        const std::string   & channel ) ;
    // 341 RPL_INVITING, "<channel> <nick>                                    ))
    std::string Fmt_RPL_INVITING (
        const std::string   & hostnick,
        const std::string   & chan, 
        const std::string   & guestnick ) ;
    // 342 RPL_SUMMONING,                  "<user> :Summoning user to IRC     ))
    std::string Fmt_RPL_SUMMONING (
        const std::string   & user ) ;
    // 346 RPL_INVITELIST,                        "<channel> <invitemask>     ))
    std::string Fmt_RPL_INVITELIST (
        const std::string   & chan, 
        const std::string   & invitemask );    
    // 347 RPL_ENDOFINVITELIST,    "<channel> :End of channel invite list     ))
    std::string Fmt_RPL_ENDOFINVITELIST (
        const std::string   & channel ) ;
    // 348 RPL_EXCEPTLIST,                     "<channel> <exceptionmask>     ))
    std::string Fmt_RPL_EXCEPTLIST (
        const std::string   & chan, 
        const std::string   & exceptionmask  ) ;    
    // 349 RPL_ENDOFEXCEPTLIST,   "<channel> :End of channel exception list   ))
    std::string Fmt_RPL_ENDOFEXCEPTLIST (
        const std::string   & channel ) ;
    // 351 RPL_VERSION,      "<version>.<debuglevel> <server> :<comments>     ))
    std::string Fmt_RPL_VERSION (
        const std::string   & ver,
        const std::string   & debug_level,
        const std::string   & host, 
        const std::string   & comments ) ;
    // 352 RPL_WHOREPLY, "<channel> <user> <host> <server> <nick> 
    // (\"H\" /\"G\" "> [\"*\"] [ ( \"@\" / \"+\" ) ] :<hopcount> <real name> ))
    std::string Fmt_RPL_WHOREPLY (
        const std::string   & nick_e,         
        const std::string   & chan, 
        const std::string   & user, 
        const std::string   & host, 
        const std::string   & server,  
        const std::string   & nick, 
        const std::string   & status,
        const std::string   & u_mode,
        const int           & hopcount, 
        const std::string   & real_name ) ;
    // 353 RPL_NAMREPLY, "( \"=\" / \"*\" / \"@\" ) <channel> :[ \"@\" / \"+\" ]
    //                        "<nick> *( \" \" [ \"@\" / \"+\" ] <nick> )     ))
    std::string Fmt_RPL_NAMREPLY (
        const std::string   & nick,
        const std::string   & chan, 
        const std::string   & user_list ) ;
    // 364 RPL_LINKS, "<mask> <server> :<hopcount> <server info>              ))
    std::string Fmt_RPL_LINKS (
        const std::string   & mask, 
        const std::string   & host, 
        const int           & hopcount, 
        const std::string   & server_info ) ;
    // 365 RPL_ENDOFLINKS,                     "<mask> :End of LINKS list     ))
    std::string Fmt_RPL_ENDOFLINKS (
        const std::string   & mask ) ;
    // 366 RPL_ENDOFNAMES,           "<nick> <channel> :End of NAMES list     ))
    std::string Fmt_RPL_ENDOFNAMES (
        const std::string   & nick, 
        const std::string   & channel ) ;
    // 367 RPL_BANLIST,                              "<channel> <banmask>     ))
    std::string Fmt_RPL_BANLIST (
        const std::string   & chan, 
        const std::string   & banmask  ) ;    
    // 368 RPL_ENDOFBANLIST,          "<channel> :End of channel ban list     ))
    std::string Fmt_RPL_ENDOFBANLIST (
        const std::string   & channel ) ;
    // 369 RPL_ENDOFWHOWAS,                        "<nick> :End of WHOWAS     ))
    std::string Fmt_RPL_ENDOFWHOWAS (
        const std::string   & nick ) ;
    // 371 RPL_INFO,        ":<string>                                        ))
    std::string Fmt_RPL_INFO (
        const std::string   & admin_info ) ;
    // 372 RPL_MOTD,        ":- <text>                                        ))
    std::string Fmt_RPL_MOTD (
        const std::string   & text ) ;
    // 374 RPL_ENDOFINFO, ":End of INFO list                                  ))
    std::string Fmt_RPL_ENDOFINFO () ;
    // 375 RPL_MOTDSTART, ":- <server> Message of the day -                   ))
    std::string Fmt_RPL_MOTDSTART (
        const std::string   & host ) ;        
    // 376 RPL_ENDOFMOTD, ":End of MOTD command                               ))
    std::string Fmt_RPL_ENDOFMOTD (
        const std::string   & nick 
    ) ;
    // 381 RPL_YOUREOPER, ":You are now an IRC operator                       ))
    std::string Fmt_RPL_YOUREOPER () ;
    // 382 RPL_REHASHING,        "<config file> :Rehashing                    ))
    std::string Fmt_RPL_REHASHING (
        const std::string   & config_file ) ;
    // 383 RPL_YOURESERVICE,               "You are service <servicename>     ))
    std::string Fmt_RPL_YOURESERVICE(
        const std::string   & servicename ) ;
    // 391 RPL_TIME, "     <server> :<string showing server's local time>     ))
    std::string Fmt_RPL_TIME (
        const std::string   & host, 
        const time_t        & time ) ;       
    // 392 RPL_USERSSTART,                         ":UserID Terminal Host     ))
    std::string Fmt_RPL_USERSSTART () ;
    // 393 RPL_USERS,                   ":<username> <ttyline> <hostname>     ))
    std::string Fmt_RPL_USERS (
        const std::string   & nick, 
        const std::string   & ttyline, 
        const std::string   & host ) ;
    // 394 RPL_ENDOFUSERS, ":End of users                                     ))
    std::string Fmt_RPL_ENDOFUSERS() ;
    // 395 RPL_NOUSERS, ":Nobody logged in                                    ))
    std::string Fmt_RPL_NOUSERS () ;    
    // 401 ERR_NOSUCHNICK, "<nickname> :No such nick/channel                  ))
    std::string Fmt_ERR_NOSUCHNICK (
        const std::string   & nick ) ;
    // 402 ERR_NOSUCHSERVER,        "<server name> :No such server            ))
    std::string Fmt_ERR_NOSUCHSERVER (
        const std::string   & server_name ) ;    
    // 403 ERR_NOSUCHCHANNEL, "<channel name> :No such channel                ))
    std::string Fmt_ERR_NOSUCHCHANNEL (
        const std::string   & channel ) ;
    // 404 ERR_CANNOTSENDTOCHAN, "<channel name> :Cannot send to channel      ))
    std::string Fmt_ERR_CANNOTSENDTOCHAN (
        const std::string   & channel ) ;
    // 405 ERR_TOOMANYCHANNELS, "<channel name> :You joined too many channels ))
    std::string Fmt_ERR_TOOMANYCHANNELS (
        const std::string   & channel ) ;
    // 406 ERR_WASNOSUCHNICK, "<nickname> :There was no such nickname         ))
    std::string Fmt_ERR_WASNOSUCHNICK (
        const std::string   & nick ) ;
    // 407 ERR_TOOMANYTARGETS,"<target> :
    //                                <error code> recipients. <abort message>))
    std::string Fmt_ERR_TOOMANYTARGETS (
        const std::string   & channel, 
        const std::string   & error_code, 
        const std::string   & abort_message ) ;
    // 408 ERR_NOSUCHSERVICE,        "<service name> :No such service         ))
    std::string Fmt_ERR_NOSUCHSERVICE (
        const std::string   & server_name  ) ;
    // 409 ERR_NOORIGIN, ":No origin specified                                ))
    std::string Fmt_ERR_NOORIGIN () ;
    // 411 ERR_NORECIPIENT,        ":No recipient given (<command>)           ))
    std::string Fmt_ERR_NORECIPIENT (
        const std::string   & command ) ;
    // 412 ERR_NOTEXTTOSEND, ":No text to send                                ))
    std::string Fmt_ERR_NOTEXTTOSEND () ;    
    // 413 ERR_NOTOPLEVEL,        "<mask> :No toplevel domain specified       ))
    std::string Fmt_ERR_NOTOPLEVEL (
        const std::string   & mask ) ;
    // 414 ERR_WILDTOPLEVEL,        "<mask> :Wildcard in toplevel domain      ))
    std::string Fmt_ERR_WILDTOPLEVEL (
        const std::string   & mask ) ;
    // 415 ERR_BADMASK,        "<mask> :Bad Server/host mask                  ))
    std::string Fmt_ERR_BADMASK (
        const std::string   & mask ) ;
    // 416 ERR_TOOMANYMATCHES, "<channel name> :You joined too many channels  ))
    std::string Fmt_ERR_TOOMANYMATCHES (
        const std::string   & channel ) ;
    // 421 ERR_UNKNOWNCOMMAND,        "<command> :Unknown command             ))
    std::string Fmt_ERR_UNKNOWNCOMMAND (
        const std::string   & command ) ;    
    // 422 ERR_NOMOTD, ":MOTD File is missing                                 ))
    std::string Fmt_ERR_NOMOTD () ;
    // 423 ERR_NOADMININFO, "<server> :No administrative info available       ))
    std::string Fmt_ERR_NOADMININFO (
        const std::string   & host ) ;
    // 424 ERR_FILEERROR,        ":File error doing <file op> on <file>       ))
    std::string Fmt_ERR_FILEERROR (
        const std::string   & fileop, 
        const std::string   & file ) ;
    // 431 ERR_NONICKNAMEGIVEN, ":No nickname given                           ))
    std::string Fmt_ERR_NONICKNAMEGIVEN () ;    
    // 432 ERR_ERRONEUSNICKNAME
    std::string Fmt_ERR_ERRONEUSNICKNAME (
        const std::string   & nick ) ;
    // 433 ERR_NICKNAMEINUSE
    std::string Fmt_ERR_NICKNAMEINUSE (
        const std::string   & nick ) ;
    // 434 ERR_ERRONEUSUSERNAME
    std::string Fmt_ERR_ERRONEUSUSERNAME (
        const std::string   & nick ) ;
    // 436 ERR_NICKCOLLISION 
    std::string Fmt_ERR_NICKCOLLISION (
        const std::string   & nick, 
        const std::string   & user,
        const std::string   & host ) ;
    // 437 ERR_UNAVAILRESOURCE, "<nick/channel>:
    //                                    Nick/channel temporarily unavailable))
    std::string Fmt_ERR_UNAVAILRESOURCE (
        const std::string   & nick ) ;
    // 441 ERR_USERNOTINCHANNEL, "<nick> <channel>:They aren't on that channel))
    std::string Fmt_ERR_USERNOTINCHANNEL (
        const std::string   & nick, 
        const std::string   & chan ) ;
    // 442 ERR_NOTONCHANNEL, "<channel> :You're not on that channel           ))
    std::string Fmt_ERR_NOTONCHANNEL (
        const std::string   & channel ) ;
    // 443 ERR_USERONCHANNEL, "<user> <channel> :is already on channel        ))
    std::string Fmt_ERR_USERONCHANNEL (
        const std::string   & user, 
        const std::string   & chan ) ;
    // 444 ERR_NOLOGIN,        "<user> :User not logged in                    ))
    std::string Fmt_NOLOGIN (
        const std::string   & user ) ;
    // 445 ERR_SUMMONDISABLED, ":SUMMON has been disabled                     ))
    std::string Fmt_ERR_SUMMONDISABLED () ;
    // 446 ERR_USERSDISABLED,        ":USERS has been disabled                ))
    std::string Fmt_ERR_USERSDISABLED (
        const std::string   & user) ;
    // 451 ERR_NOTREGISTERED, ":You have not registered                       ))
    std::string Fmt_ERR_NOTREGISTERED () ;
    // 461 ERR_NEEDMOREPARAMS,        "<command> :Not enough parameters       ))
    std::string Fmt_ERR_NEEDMOREPARAMS (
        const std::string   & command ) ;
    // 462 ERR_ALREADYREGISTRED,  ":Unauthorized command (already registered) ))
    std::string Fmt_ERR_ALREADYREGISTRED () ;
    // 463 ERR_NOPERMFORHOST,      ":Your host isn't among the privileged     ))
    std::string Fmt_ERR_NOPERMFORHOST () ;
    // 464 ERR_PASSWDMISMATCH,                       ":Password incorrect     ))
    std::string Fmt_ERR_PASSWDMISMATCH () ;
    // 465 ERR_YOUREBANNEDCREEP, "       :You are banned from this server     ))
    std::string Fmt_ERR_YOUREBANNEDCREEP () ;
    // 466 ERR_YOUWILLBEBANNED, "                                             ))
    std::string Fmt_ERR_YOUWILLBEBANNED () ;    
    // 467 ERR_KEYSET, "<channel> :Channel key already set                    ))
    std::string Fmt_ERR_KEYSET (
        const std::string   & channel ) ;
    // 471 ERR_CHANNELISFULL, "<channel> :Cannot join channel (+l)            ))
    std::string Fmt_ERR_CHANNELISFULL (
        const std::string   & channel ) ;
    // 472 ERR_UNKNOWNMODE,"<char> :is unknown mode char to me for <channel>  ))
    std::string Fmt_ERR_UNKNOWNMODE (
        const char          & letra, 
        const std::string   & chan ) ;
    // 473 ERR_INVITEONLYCHAN, "<channel> :Cannot join channel (+i)           ))
    std::string Fmt_ERR_INVITEONLYCHAN (
        const std::string   & channel ) ;
    // 474 ERR_BANNEDFROMCHAN, "<channel> :Cannot join channel (+b)           ))
    std::string Fmt_ERR_BANNEDFROMCHAN (
        const std::string   & channel ) ;
    // 475 ERR_BADCHANNELKEY, "<channel> :Cannot join channel (+k)            ))
    std::string Fmt_ERR_BADCHANNELKEY (
        const std::string   & channel ) ;
    // 476 ERR_BADCHANMASK, "<channel> :Bad Channel Mask                      ))
    std::string Fmt_ERR_BADCHANMASK (
        const std::string   & channel ) ;
    // 477 ERR_NOCHANMODES, "<channel> :Channel doesn't support modes         ))
    std::string Fmt_ERR_NOCHANMODES (
        const std::string   & channel ) ;
    // 478 ERR_BANLISTFULL,       "<channel> <char> :Channel list is full     ))
    std::string Fmt_ERR_BANLISTFULL (
        const std::string   & chan, 
        const char          & letra ) ;
    // 481 ERR_NOPRIVILEGES, ": Permission Denied- You're not an IRC operator ))
    std::string Fmt_RERR_NOPRIVILEGES () ;    
    // 482 ERR_CHANOPRIVSNEEDED, " <channel> :You're not channel operator     ))
    std::string Fmt_ERR_CHANOPRIVSNEEDED (
        const std::string   & channel ) ;
    // 483 ERR_CANTKILLSERVER,                 ":You can't kill a server!     ))
    std::string Fmt_ERR_CANTKILLSERVER () ;
    // 484 ERR_RESTRICTED, "              :Your connection is restricted!     ))
    std::string Fmt_ERR_RESTRICTED () ;
    // 485 ERR_UNIQOPPRIVSNEEDED,  ":You're not the original channel operator ))
    std::string Fmt_ERR_UNIQOPPRIVSNEEDED () ;
    // 491 ERR_NOOPERHOST,                     ":No O-lines for your host     ))
    std::string Fmt_ERR_NOOPERHOST () ;
    // 501 ERR_UMODEUNKNOWNFLAG,                      ":Unknown MODE flag     ))
    std::string Fmt_ERR_UMODEUNKNOWNFLAG () ;
    // 502 ERR_USERSDONTMATCH,       ":Cannot change mode for other users     ))
    std::string Fmt_ERR_USERSDONTMATCH () ;
    // 503 ERR_UMODEUNTREATED        "Flag <flag> out of 42 FT_IRC scope"     ))
    std::string Fmt_ERR_UMODEUNTREATED (
        const std::string &    flag ) ;
    // 504 ERR_COMMANDUNTREATED  
    //                    "<nick> Command <command> out of 42 FT_IRC scope"   ))
    std::string Fmt_ERR_COMMANDUNTREATED (
        const std::string &    nick,        
        const std::string &    command ) ;

    // 600 RPL_PRIVMSG     ":<nick_e>!<user>@<host> PRIVMSG <target> :<msg>"  ))
    std::string Fmt_RPL_PRIVMSG(
        const std::string &    nick_e,
        const std::string &    user, 
        const std::string &    host, 
        const std::string &    target,                                 
        const std::string &    msg ) ;

    // 601 RPL_KICK ":<nick_e>!<user>@<host> KICK <chan> <nick> :<comment>"  ))
    std::string Fmt_RPL_KICK(
        const std::string &    nick_e,
        const std::string &    user, 
        const std::string &    host, 
        const std::string &    chan,
        const std::string &    nick,                             
        const std::string &    comment ) ;

    // 602 RPL_PART     ":<nick_e>!<user>@<host> PART <chan> :<reason>"  ))
    std::string Fmt_RPL_PART(
        const std::string &    nick_e,
        const std::string &    user, 
        const std::string &    host, 
        const std::string &    chan,                                 
        const std::string &    reason ) ;

    // Método para devolver un puntero constante a un mensaje por su código
    
    const std::string* getMsgByCode(int code) const;

    // Método para mostrar la información de un mensaje por consola
    void printMessage(int code) const;

    // Nuevo método público para obtener un mensaje con sustitución de etiquetas
    std::string getFmtMsg(int messageNumber,
    const std::map<std::string, std::string>  & tags
    ) const;
    // Nuevo método público para obtener un mensaje con sustitución de etiquetas
    std::string getFmtMsg_no_prefix(int messageNumber,
    const std::map<std::string, std::string>  & tags
    ) const;

private:
    // Estructura de datos que almacena todos los mensajes de forma privada
    std::map<int, std::string> messages_;

    // Método privado para inicialización del mapa, llamado por el constructor
    void initializeMessages();

    // Nuevo método privado para realizar la sustitución de una sola etiqueta
    std::string _substituteTag(
 const std::string& text,
 const std::string& substitutionTag,
 const std::string& substitutionText
    ) const;
};

#endif // IRCMESSAGEMANAGER_HPP

