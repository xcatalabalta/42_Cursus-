#include "IrcMM.class.hpp"




// Constructor: llama al método de inicialización
IrcMM::IrcMM() {
    initializeMessages();
}
// Constructor por copia
IrcMM::IrcMM( IrcMM const & other) 
    : messages_(other.messages_){
    
}

// Operador de assignacion
IrcMM & IrcMM::operator=(IrcMM const & other) {
    if (this != &other) {
        this->messages_ = other.messages_;
    }
	return *this ;
}
// Destructor
IrcMM::~IrcMM() {
    
}

// 001 RPL_WELCOME 
std::string IrcMM::Fmt_RPL_WELCOME (
    const std::string   & nick, 
    const std::string   & user, 
    const std::string   & host ) 
{
    std::map<std::string, std::string>  tags ;
    tags["<nick>"] = nick;
    tags["<user>"] = user;
    tags["<host>"] = host;
    return this->getFmtMsg(RPL_WELCOME, tags) ;
}

// 002 RPL_YOURHOST,      "Your host is <servername>, running version <ver>   ))
std::string IrcMM::Fmt_RPL_YOURHOST (
    const std::string   & server, 
    const std::string   & version ) 
{
    std::map<std::string, std::string>  tags ;
    tags["<servername>"] = server;
    tags["<ver>"] = version;
    return this->getFmtMsg(RPL_YOURHOST, tags) ;
}    
    
// 003 RPL_CREATED,                       "This server was created <date>     ))
std::string IrcMM::Fmt_RPL_CREATED (
    const time_t & time ) 
{
    std::map<std::string, std::string>  tags ;
    // Convert time_t to a tm struct for local time
    tm* local_time = localtime(&time);

    // Use a character buffer to format the output
    char buffer[80];
    // Format the date and time string
    // %Y = Year with century (e.g., 2025)
    // %m = Month as a decimal number (01-12)
    // %d = Day of the month (01-31)
    // %H = Hour in 24-hour format (00-23)
    // %M = Minute (00-59)
    // %S = Second (00-59)
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", local_time);
    tags["<date>"] = buffer;
    return this->getFmtMsg(RPL_CREATED, tags) ;
}

// 004 RPL_MYINFO, "<servername> <version> <available user modes> 
//                                             "<available channel modes>     ))
std::string IrcMM::Fmt_RPL_MYINFO (
    const std::string   & server,
    const std::string   & version, 
    const std::string   & u_modes, 
    const std::string   & c_modes )  
    {
        std::map<std::string, std::string>  tags ;      
        tags["<servername>"] = server;
        tags["<version>"] = version;
        tags["<available user modes>"] = u_modes;
        tags["<available channel modes>"] = c_modes;
        return this->getFmtMsg(RPL_MYINFO, tags) ;
    }    
    
// 005 RPL_BOUNCE,          "Try server <server name>, port <port number>     ))
std::string IrcMM::Fmt_RRPL_BOUNCE (
    const std::string   & server, 
    const int           & port_number ) 
{
    std::map<std::string, std::string>  tags ;
    std::stringstream ss;
    tags["<server name>"] = server;
    ss << port_number ;
    tags["<port number>"] = ss.str();
    return this->getFmtMsg(RPL_BOUNCE, tags) ;
}  

// 200 RPL_TRACELINK, "Link <version & debug level> 
//          <destination> <next server> V<protocol version> 
//              <link uptime in seconds> <backstream sendq> <upstream sendq>" ))
std::string IrcMM::Fmt_RPL_TRACELINK (
    const std::string   & ver,
    const std::string   & debug,
    const std::string   & destination,
    const std::string   & next_server,
    const std::string   & version,
    const int           & uptime,
    const int           & bs_q_size, 
    const int           & us_q_size)  
    {
        std::map<std::string, std::string>  tags ;
        std::stringstream ss;
        tags["<version & debug level>"] = ver + ":" + debug;
        tags["<destination>"] = destination;
        tags["<next server>"] = next_server;
        tags["<protocol version>"] = version;
        ss  << uptime ;
        tags["<link uptime in seconds>"] = ss.str();
        ss.str("");
        ss.clear();
        ss  << bs_q_size ;
        tags["<backstream sendq>"] = ss.str();
        ss.str("");
        ss.clear();
        ss  << us_q_size ;
        tags["<upstream sendq>"] = ss.str();
        return this->getFmtMsg(RPL_TRACELINK, tags) ;
    }    
    
// 201 RPL_TRACECONNECTING,                        "Try. <class> <server>     ))
std::string IrcMM::Fmt_RPL_TRACECONNECTING (
    const char          & clase,
    const std::string   & server )  
{
    std::map<std::string, std::string>  tags ;

    tags["<class>"] = clase;
    tags["<server>"] = server;
    return this->getFmtMsg(RPL_TRACECONNECTING, tags) ;
}    
    
// 202 RPL_TRACEHANDSHAKE,                         "H.S. <class> <server>     ))
std::string IrcMM::Fmt_RPL_TRACEHANDSHAKE (
    const char          & clase, 
    const std::string   & server ) 
{
    std::map<std::string, std::string>  tags ;

    tags["<class>"] = clase;
    tags["<server>"] = server;
    return this->getFmtMsg(RPL_TRACEHANDSHAKE, tags) ;
}    

// 203 RPL_TRACEUNKNOWN,  "???? <class> [<client IP address in dot form>]     ))
std::string IrcMM::Fmt_RPL_TRACEUNKNOWN (
    const char          & clase, 
    const std::string   & ip ) 
{
    std::map<std::string, std::string>  tags ;
    tags["<class>"] = clase;
    tags["<client IP address in dot form>"] = ip;
    return this->getFmtMsg(RPL_TRACEUNKNOWN, tags) ;
}      

// 204 RPL_TRACEOPERATOR,                            "Oper <class> <nick>     ))
std::string IrcMM::Fmt_RPL_TRACEOPERATOR (
    const char          & clase, 
    const std::string   & nick ) 
{
    std::map<std::string, std::string>  tags ;
    tags["<class>"] = clase;
    tags["<nick>"] = nick;
    return this->getFmtMsg(RPL_TRACEOPERATOR, tags) ;
}     

// 205 RPL_TRACEUSER,                                "User <class> <nick>     ))
std::string IrcMM::Fmt_RPL_TRACEUSER (
    const char          & clase, 
    const std::string   & nick ) 
{
    std::map<std::string, std::string>  tags ;
    tags["<class>"] = clase;
    tags["<nick>"] = nick;
    return this->getFmtMsg(RPL_TRACEUSER, tags) ;
}      

// 206 RPL_TRACESERVER, "Serv <class> <int>S 
//      <int>C <server>   
//      "<nick!user|*!*>@<host|server> V<protocol version>                    ))
std::string IrcMM::Fmt_RPL_TRACESERVER (
    const char          & clase,
    const int           & servidores_conectados,
    const int           & clientes_conectados,
    const std::string   & host_local,
    const std::string   & user,
    const std::string   & host_remoto,
    const std::string   & version)
    {
        std::map<std::string, std::string>  tags ;
        std::stringstream ss;
        tags["<class>"] = clase;
        ss << servidores_conectados ;
        tags["<integer1>"] = ss.str();
        ss.str("") ;
        ss.clear() ;
        ss << clientes_conectados ;
        tags["<integer2>"] = ss.str();
        tags["<server>"] = host_local;
        tags["<user>"] = user;
        tags["<host>"] = host_remoto;                        
        tags["<protocol version>"] = version;
        return this->getFmtMsg(RPL_TRACESERVER, tags) ;
    }    

// 207 RPL_TRACERVICE,       "Service <class> <name> <type> <active type>     ))
std::string IrcMM::Fmt_RPL_RPL_TRACERVICE (
    const char          & clase,
    const std::string   & name,    
    const std::string   & type,
    const std::string   & server ) 
    {
        std::map<std::string, std::string>  tags ;
        tags["<class>"] = clase;
        tags["<name>"] = name;
        tags["<type>"] = type;
        tags["<active type>"] = server;
        return this->getFmtMsg(RPL_TRACERVICE, tags) ;
    }    

// 208 RPL_TRACENEWTYPE,                       "<newtype> 0 <client name>     ))
std::string IrcMM::Fmt_RPL_TRACENEWTYPE (
    const std::string   & type, 
    const std::string   & user ) 
{
    std::map<std::string, std::string>  tags ;
    tags["<newtype>"] = type;
    tags["<client name>"] = user;
    return this->getFmtMsg(RPL_TRACENEWTYPE, tags) ;
}     

// 209 RPL_TRACECLASS,                             "Class <class> <count>     ))
std::string IrcMM::Fmt_RPL_TRACECLASS (
    const char          & clase, 
    const int           & count) 
{
    std::map<std::string, std::string>  tags ;
    std::stringstream ss ;
    tags["<class>"] = clase;
    ss << count ;
    tags["<count>"] = ss.str();
    return this->getFmtMsg(RPL_TRACECLASS, tags) ;
}    

// 210 RPL_TRACERECONNECT,                                       "Unused.     ))
std::string IrcMM::Fmt_RPL_TRACERECONNECT ()  
{
    return *this->getMsgByCode(RPL_TRACERECONNECT) ;
}

// 211 RPL_STATSLINKINFO,        "<linkname> <sendq> <sent messages> 
//       <sent Kbytes> "<received messages> <received Kbytes> <time open>     ))
std::string IrcMM::Fmt_RPL_STATSLINKINFO (const std::string & link, 
    const int           & size, 
    const int           & s_msg, 
    const int           & s_Kbytes, 
    const int           & r_msg, 
    const int           & r_Kbytes, 
    const int           & seconds) 
{
    std::map<std::string, std::string>  tags ;
    std::stringstream ss;
    tags["<linkname>"] = link;
    ss << size ;
    tags["<sendq>"] = ss.str();
    ss.str("");
    ss.clear();
    ss  << s_msg ;
    tags["<sent messages>"] = ss.str();
    ss.str("");
    ss.clear();
    ss  << s_Kbytes ;
    tags["<sent Kbytes>"] = ss.str();
    ss.str("");
    ss.clear();
    ss  << r_msg ;
    tags["<received messages>"] = ss.str();
    ss.str("");
    ss.clear();
    ss  << r_Kbytes ;
    tags["<received Kbytes>"] = ss.str();
    ss.str("");
    ss.clear();
    ss  << seconds ;
    tags["<time open>"] = ss.str();

    return this->getFmtMsg(RPL_STATSLINKINFO, tags) ;
}    

// 212 RPL_STATSCOMMANDS,      "<command> <count> <byte count> <remote count> ))
std::string IrcMM::Fmt_RPL_STATSCOMMANDS (
    const std::string   & command,
    const int           & count,
    const int           & byte_count,
    const int           & remote_count )  
{
    std::map<std::string, std::string>  tags ;
    std::stringstream ss;
    tags["<command>"] = command;
    ss << count ;
    tags["<count>"] = ss.str();
    ss.str("") ;
    ss.clear() ;
    ss << byte_count ;
    tags["<byte count>"] = ss.str();
    ss.str("") ;
    ss.clear() ;
    ss << remote_count ;
    tags["<remote count>"] = ss.str();
    return this->getFmtMsg(RPL_STATSCOMMANDS, tags) ;
}    

// 219 RPL_ENDOFSTATS,               "<stats letter> :End of STATS report     ))
std::string IrcMM::Fmt_RPL_ENDOFSTATS (
    const char          & letter )  
{
    std::map<std::string, std::string>  tags ;
    tags["<stats letter>"] = letter;
    return this->getFmtMsg(RPL_ENDOFSTATS, tags) ;
}

// 221 RPL_UMODEIS,                                   "<user mode string>     ))
std::string IrcMM::Fmt_RPL_UMODEIS (
    const std::string   & u_mode) 
{
    std::map<std::string, std::string>  tags ;
    tags["<user mode string>"] = u_mode;
    return this->getFmtMsg(RPL_UMODEIS, tags) ;
}

// 234 RPL_SERVLIST, "<name> <server> <mask> <type> <hopcount> <info>         ))
std::string IrcMM::Fmt_RPL_SERVLIST (
    const std::string   & nick,
    const std::string   & host, 
    const std::string   & mask,
    const std::string   & type, 
    const int           & hopcount, 
    const std::string   & server_info )  
    {
        std::map<std::string, std::string>  tags ;
        std::stringstream ss;
        tags["<name>"] = nick;
        tags["<server>"] = host;
        tags["<mask>"] = mask;
        tags["<type>"] = type;
        ss  << hopcount ;
        tags["<hopcount>"] = ss.str();
        tags["<info>"] = server_info;
        return this->getFmtMsg(RPL_SERVLIST, tags) ;
    }    

// 235 RPL_SERVLISTEND,            "<mask> <type> :End of service listing     ))
std::string IrcMM::Fmt_RPL_SERVLISTEND (
    const std::string   & mask, 
    const std::string   & type ) 
{
    std::map<std::string, std::string>  tags ;
    tags["<mask>"] = mask;
    tags["<type>"] = type;
    return this->getFmtMsg(RPL_SERVLISTEND, tags) ;
} 

// 242 RPL_STATSUPTIME,                  ":Server Up %d days %d:%02d:%02d     ))
std::string IrcMM::Fmt_RPL_STATSUPTIME ()  
{
    return *this->getMsgByCode(RPL_STATSUPTIME) ;
}

// 251 RPL_LUSERCLIENT,        ":There are <integer> users and <integer> 
//                                         services on "<integer> servers     ))
std::string IrcMM::Fmt_RPL_LUSERCLIENT (
    const int           & clients, 
    const int           & services, 
    const int           & servers )  
{
    std::map<std::string, std::string>  tags ;
    std::stringstream ss;
    ss << clients ;
    tags["<integer1>"] = ss.str();
    ss.str("");
    ss.clear();
    ss  << services ;
    tags["<integer2>"] = ss.str();
    ss.str("");
    ss.clear();
    ss  << servers ;
    tags["<integer3>"] = ss.str();
    return this->getFmtMsg(RPL_LUSERCLIENT, tags) ;
}  

// 252 RPL_LUSEROP,                        "<integer> :operator(s) online     ))
std::string IrcMM::Fmt_RPL_LUSEROP (
    const int           & operators ) 
{
    std::map<std::string, std::string>  tags ;
    std::stringstream ss;
    ss << operators ;
    tags["<nick>"] = ss.str();
    return this->getFmtMsg(RPL_ISON, tags) ;
}
        
// 253 RPL_LUSERUNKNOWN,                "<integer> :unknown connection(s)     ))
std::string IrcMM::Fmt_RPL_LUSERUNKNOWN (
    const int           & connections) 
{
    std::map<std::string, std::string>  tags ;
    std::stringstream ss;
    ss << connections ;
    tags["<integer>"] = ss.str();
    return this->getFmtMsg(RPL_LUSEROP, tags) ;
}
        
// 254 RPL_LUSERCHANNELS,                     "<integer> :channels formed     ))
std::string IrcMM::Fmt_RPL_LUSERCHANNELS (
    const int           & channels ) 
{
    std::map<std::string, std::string>  tags ;
    std::stringstream ss;
    ss << channels ;
    tags["<integer>"] = ss.str();
    return this->getFmtMsg(RPL_LUSERCHANNELS, tags) ;
}
        
// 255 RPL_LUSERME,    ":I have <integer1> clients and <integer2> servers     ))
std::string IrcMM::Fmt_RPL_LUSERME (
    const int           & clients, 
    const int           & servers ) 
{
    std::map<std::string, std::string>  tags ;
    std::stringstream ss;
    ss << clients;
    tags["<integer1>"] = ss.str();
    ss.str("");
    ss.clear();
    ss  << servers ;
    tags["<integer2>"] = ss.str();
    return this->getFmtMsg(RPL_LUSERME, tags) ;
}    

// 256 RPL_ADMINME,                        "<server> :Administrative info     ))
std::string IrcMM::Fmt_RPL_ADMINME (
    const std::string   & host) 
{
    std::map<std::string, std::string>  tags ;
    tags["<server>"] = host;
    return this->getFmtMsg(RPL_ADMINME, tags) ;
}

// 257 RPL_ADMINLOC1,                                      ":<admin info>     ))
std::string IrcMM::Fmt_RPL_ADMINLOC1 (
    const std::string   & admin_info ) 
{
    std::map<std::string, std::string>  tags ;
    tags["<admin info>"] = admin_info;
    return this->getFmtMsg(RPL_ADMINLOC1, tags) ;
}

// 258 RPL_ADMINLOC2,                                      ":<admin info>     ))
std::string IrcMM::Fmt_RPL_ADMINLOC2 (
    const std::string   & admin_info) 
{
    std::map<std::string, std::string>  tags ;
    tags["<admin info>"] = admin_info;
    return this->getFmtMsg(RPL_ADMINLOC2, tags) ;
}

// 259 RPL_ADMINEMAIL,                                     ":<admin info>     ))
std::string IrcMM::Fmt_RPL_ADMINEMAIL (
    const std::string   & admin_info )  
{
    std::map<std::string, std::string>  tags ;
    tags["<admin info>"] = admin_info ;
    return this->getFmtMsg(RPL_ADMINEMAIL, tags) ;
}

// 261 RPL_TRACELOG,                        "File <logfile> <debug level>     ))
std::string IrcMM::Fmt_RPL_TRACELOG (
    const std::string   & logfile, 
    const std::string   & debug ) 
{
    std::map<std::string, std::string>  tags ;
    tags["<logfile>"] = logfile;
    tags["<debug level>"] = debug;
    return this->getFmtMsg(RPL_TRACELOG, tags) ;
}      

// 262 RPL_TRACEEND, "<server name> <version & debug level> :End of TRACE     ))
std::string IrcMM::Fmt_RPL_TRACEEND (
    const std::string   & host, 
    const std::string   & ver,
    const std::string   & debug )  
    {
        std::map<std::string, std::string>  tags ;
        tags["<server name>"] = host;
        tags["<version & debug level>"] = ver + ":" +debug;
        return this->getFmtMsg(RPL_TRACEEND, tags) ;
    }    

// 263 RPL_TRYAGAIN,           "<command> :Please wait a while and try again. ))
std::string IrcMM::Fmt_RPL_TRYAGAIN (
    const std::string   & command ) 
{
    std::map<std::string, std::string>  tags ;
    tags["<command>"] = command;
    return this->getFmtMsg(RPL_TRYAGAIN, tags) ;
}

// 301 RPL_AWAY,                                  "<nick> :<away message>     ))
std::string IrcMM::Fmt_RPL_AWAY (
    const std::string   & nick,
    const std::string   & message )  
{
    std::map<std::string, std::string>  tags ;

    tags["<nick>"] = nick;
    tags["<away message>"] = message;
    return this->getFmtMsg(RPL_AWAY, tags) ;
}    

// 302 RPL_USERHOST,                       ":*1<reply> *( \" \" <reply> )     ))
std::string IrcMM::Fmt_RPL_USERHOST (
    const std::string   & reply ) 
{
    std::map<std::string, std::string>  tags ;
    tags["<reply>"] = reply;
    return this->getFmtMsg(RPL_USERHOST, tags) ;
}
    
// 303 RPL_ISON,                             ":*1<nick> *( \" \" <nick> )     ))
std::string IrcMM::Fmt_RPL_ISON (
    const std::string   & nick ) 
{
    std::map<std::string, std::string>  tags ;
    tags["<nick>"] = nick;
    return this->getFmtMsg(RPL_ISON, tags) ;
}

// 305 RPL_UNAWAY,               ":You are no longer marked as being away     ))
std::string IrcMM::Fmt_RPL_UNAWAY ()  
{
    return *this->getMsgByCode(RPL_UNAWAY) ;
}

// 306 RPL_NOWAWAY,                  ":You have been marked as being away     ))
std::string IrcMM::Fmt_RPL_NOWAWAY ()  
{
    return *this->getMsgByCode(RPL_NOWAWAY) ;
}

// 311 RPL_WHOISUSER
std::string IrcMM::Fmt_RPL_WHOISUSER (
    const std::string   & nick, 
    const std::string   & user,
    const std::string   & host,
    const std::string   & real_name ) 
{
    std::map<std::string, std::string>  tags ;
    //tags[""] = ;
    tags["<nick>"] = nick;
    tags["<user>"] = user;
    tags["<host>"] = host;
    tags["<real name>"] = real_name;

    return this->getFmtMsg(RPL_WHOISUSER, tags) ;
}

// 312 RPL_WHOISSERVER,                   "<nick> <server> :<server info>     ))
std::string IrcMM::Fmt_RPL_WHOISSERVER (
    const std::string   & nick,
    const std::string   & host,
    const std::string   & server_info )  
{
    std::map<std::string, std::string>  tags ;
    tags["<nick>"] = nick;
    tags["<server>"] = host;
    tags["<server info>"] = server_info;
    return this->getFmtMsg(RPL_WHOISSERVER, tags) ;
}    

// 313 RPL_WHOISOPERATOR,                     "<nick> :is an IRC operator     ))
std::string IrcMM::Fmt_RPL_WHOISOPERATOR (
    const std::string   & nick )  
{
    std::map<std::string, std::string>  tags ;
    tags["<nick>"] = nick;
    return this->getFmtMsg(RPL_WHOISOPERATOR, tags) ;
}

// 314 RPL_WHOWASUSER 
std::string IrcMM::Fmt_RPL_WHOWASUSER (
    const std::string   & nick, 
    const std::string   & user,
    const std::string   & host,
    const std::string   & real_name ) 
{
    std::map<std::string, std::string>  tags ;
    //tags[""] = ;
    tags["<nick>"] = nick;
    tags["<user>"] = user;
    tags["<host>"] = host;
    tags["<real name>"] = real_name;

    return this->getFmtMsg(RPL_WHOWASUSER, tags) ;
}

// 315 RPL_ENDOFWHO,                      "<nick> <chan> :End of WHO list     ))
std::string IrcMM::Fmt_RPL_ENDOFWHO (
    const std::string   &  nick,    
    const std::string   &  chan ) 
{
    std::map<std::string, std::string>  tags ;
    tags["<nick>"] = nick;
    tags["<chan>"] = chan;
    return this->getFmtMsg(RPL_ENDOFWHO, tags) ;
}
    
// 317 RPL_WHOISIDLE,                     "<nick> <integer> :seconds idle     ))
std::string IrcMM::Fmt_RPL_WHOISIDLE (
    const std::string   & nick, 
    const int           & seconds ) 
{
    std::map<std::string, std::string>  tags ;
    std::stringstream ss;
    ss << seconds ;
    tags["<nick>"] = nick;
    tags["<integer>"] = ss.str();
    return this->getFmtMsg(RPL_WHOISIDLE, tags) ;
}   

// 318 RPL_ENDOFWHOIS,                         "<nick> :End of WHOIS list     ))
std::string IrcMM::Fmt_RPL_ENDOFWHOIS (
    const std::string   & nick )  
{
    std::map<std::string, std::string>  tags ;
    tags["<nick>"] = nick;
    return this->getFmtMsg(RPL_ENDOFWHOIS, tags) ;
}

// 319 RPL_WHOISCHANNELS, "<nick> :*( ( \"@\" / \"+\" ) <channel> \" \" )     ))
std::string IrcMM::Fmt_RPL_WHOISCHANNELS (
    const std::string   & nick, 
    const std::string   & chan )
{
    std::map<std::string, std::string>  tags ;
    tags["<nick>"] = nick;
    tags["<channel>"] = chan;
    return this->getFmtMsg(RPL_WHOISCHANNELS, tags) ;
}

// 321 RPL_LISTSTART,                                          "Obsolete.     ))
std::string IrcMM::Fmt_RPL_LISTSTART()  
{
    return *this->getMsgByCode(RPL_LISTSTART) ;
}

// 322 RPL_LIST,                          " <nick> <channel> <# visible> :<topic>     ))
std::string IrcMM::Fmt_RPL_LIST (
    const std::string   & nick ,
    const std::string   & chan, 
    const int           & u_visibles, 
    const std::string   & topic)  
{
    std::map<std::string, std::string>  tags ;
    std::stringstream ss;
    ss << u_visibles;
    tags["<nick>"] = nick;
    tags["<# visible>"] = ss.str();
    tags["<channel>"] = chan;
    tags["<topic>"] = topic;
    return this->getFmtMsg(RPL_LIST, tags) ;
}    

// 323 RPL_LISTEND,                                         ":End of LIST     ))
std::string IrcMM::Fmt_RPL_LISTEND (
    const std::string   & nick
)  
{
    std::map<std::string, std::string>  tags ;
    tags["<nick>"] = nick;
    return this->getFmtMsg(RPL_LISTEND, tags) ;
}

// 324 RPL_CHANNELMODEIS,          "<nick> <channel> <mode> <mode params>     ))
std::string IrcMM::Fmt_RPL_CHANNELMODEIS (
    const std::string   & nick,    
    const std::string   & chan,
    const std::string   & c_modes,
    const std::string   & parametros )  
{
    std::map<std::string, std::string>  tags ;
    tags["<nick>"] = nick;
    tags["<channel>"] = chan;
    tags["<mode>"] = c_modes;
    tags["<mode params>"] = parametros;
    return this->getFmtMsg(RPL_CHANNELMODEIS, tags) ;
}    
 
// 325 RPL_UNIQOPIS,                                "<channel> <nickname>     ))
std::string IrcMM::Fmt_RPL_UNIQOPIS (
    const std::string   & chan, 
    const std::string   & nick )
{
    std::map<std::string, std::string>  tags ;
    tags["<nickname>"] = nick;
    tags["<channel>"] = chan;
    return this->getFmtMsg(RPL_UNIQOPIS, tags) ;
}

// 331 RPL_NOTOPIC,                           "<channel> :No topic is set     ))
std::string IrcMM::Fmt_RPL_NOTOPIC (
    const std::string   & channel ) 
{
    std::map<std::string, std::string>  tags ;
    tags["<channel>"] = channel;
    return this->getFmtMsg(RPL_NOTOPIC, tags) ;
}

// 332 RPL_TOPIC,                                     "<nick> <channel> :<topic>     ))
std::string IrcMM::Fmt_RPL_TOPIC (
    const std::string   & nick,
    const std::string   & channel,
    const std::string   & topic )  
{
    std::map<std::string, std::string>  tags ;

    tags["<nick>"] = nick;
    tags["<topic>"] = topic;
    tags["<channel>"] = channel;
    return this->getFmtMsg(RPL_TOPIC, tags) ;
}    
  
// 333 RPL_JOIN,                       ":<nick>!<user>@<host> JOIN:<channel>"))
std::string IrcMM::Fmt_RPL_JOIN (
    const std::string   & nick,    
    const std::string   & user,
    const std::string   & host,     
    const std::string   & channel)  
{
    std::map<std::string, std::string>  tags ;

    tags["<nick>"] = nick;
    tags["<user>"] = user;
    tags["<host>"] = host;        
    tags["<channel>"] = channel;
    return this->getFmtMsg_no_prefix(RPL_JOIN, tags) ;
}   
// 340 RPL_INVITED, 
    //                ":<hostnick>!<user>@<host> INVITE <guestnick> :<channel>))
    std::string IrcMM::Fmt_RPL_INVITED (
        const std::string   & hostnick,
        const std::string   & user,
        const std::string   & host,        
        const std::string   & guestnick,
        const std::string   & channel )
{
    std::map<std::string, std::string>  tags ;
    tags["<hostnick>"] = hostnick;
    tags["<user>"] = user;
    tags["<host>"] = host;        
    tags["<guestnick>"] = guestnick;    
    tags["<channel>"] = channel;
    return this->getFmtMsg_no_prefix(RPL_INVITED, tags) ;
}        
// 341 RPL_INVITING,                                    "<channel> <nick>     ))
    std::string IrcMM::Fmt_RPL_INVITING (
        const std::string   & hostnick,
        const std::string   & chan, 
        const std::string   & guestnick )
{
    std::map<std::string, std::string>  tags ;
    tags["<hostnick>"] = hostnick;
    tags["<guestnick>"] = guestnick;    
    tags["<channel>"] = chan;
    return this->getFmtMsg(RPL_INVITING, tags) ;
}

// 342 RPL_SUMMONING,                      "<user> :Summoning user to IRC     ))
std::string IrcMM::Fmt_RPL_SUMMONING (
    const std::string   & user ) 
{
    std::map<std::string, std::string>  tags ;
    tags["<user>"] = user;
    return this->getFmtMsg(RPL_SUMMONING, tags) ;
}
    
// 346 RPL_INVITELIST,                            "<channel> <invitemask>     ))
std::string IrcMM::Fmt_RPL_INVITELIST (
    const std::string   & chan,
    const std::string   & invitemask ) 
{
    std::map<std::string, std::string>  tags ;

    tags["<invitemask>"] = invitemask;
    tags["<channel>"] = chan;
    return this->getFmtMsg(RPL_INVITELIST, tags) ;
}    

// 347 RPL_ENDOFINVITELIST,        "<channel> :End of channel invite list     ))
std::string IrcMM::Fmt_RPL_ENDOFINVITELIST (
    const std::string   & channel ) 
{
    std::map<std::string, std::string>  tags ;
    tags["<channel>"] = channel;
    return this->getFmtMsg(RPL_ENDOFINVITELIST, tags) ;
}
  
// 348 RPL_EXCEPTLIST,                         "<channel> <exceptionmask>     ))
std::string IrcMM::Fmt_RPL_EXCEPTLIST (
    const std::string   & chan,
    const std::string   & exceptionmask  )  
{
    std::map<std::string, std::string>  tags ;
    tags["<exceptionmask>"] = exceptionmask;
    tags["<channel>"] = chan;
    return this->getFmtMsg(RPL_EXCEPTLIST, tags) ;
}    

// 349 RPL_ENDOFEXCEPTLIST,     "<channel> :End of channel exception list     ))
std::string IrcMM::Fmt_RPL_ENDOFEXCEPTLIST (
    const std::string   & channel ) 
{
    std::map<std::string, std::string>  tags ;
    tags["<channel>"] = channel;
    return this->getFmtMsg(RPL_ENDOFEXCEPTLIST, tags) ;
}

// 351 RPL_VERSION,          "<version>.<debuglevel> <server> :<comments>     ))
std::string IrcMM::Fmt_RPL_VERSION (
    const std::string   & ver,
    const std::string   & debug_level,
    const std::string   & host,
    const std::string   & comments )
    {
        std::map<std::string, std::string>  tags ;
        std::stringstream ss;
        tags["<version>"] = ver;
        tags["<debuglevel>"] = debug_level;
        tags["<server>"] = host ;
        tags["<comments>"] = comments;
        return this->getFmtMsg(RPL_VERSION, tags) ;
    }

// 352 RPL_WHOREPLY, 
//<nick_e> <channel> ~<user> <host> <server> <mode><nick> <status> :<hopcount> <real name>"
std::string IrcMM::Fmt_RPL_WHOREPLY (
    const std::string   & nick_e,
    const std::string   & chan,
    const std::string   & user,
    const std::string   & host,
    const std::string   & server,
    const std::string   & nick,
    const std::string   & status,
    const std::string   & u_mode,    
    const int           & hopcount,
    const std::string   & real_name ) 
    {
        std::map<std::string, std::string>  tags ;
        std::stringstream ss;
        tags["<nick_e>"] = nick_e;        
        tags["<channel>"] = chan;
        tags["<user>"] = user;
        tags["<host>"] = host;
        tags["<server>"] = server;
        tags["<nick>"] = nick;
        tags["<status>"] = status;
        tags["<mode>"] = u_mode;                
        ss  << hopcount ;
        tags["<hopcount>"] = ss.str();
        tags["<real name>"] = real_name;
        return this->getFmtMsg(RPL_WHOREPLY, tags) ;
    }

// 353 RPL_NAMREPLY,        "( \"=\" / \"*\" / \"@\" ) 
// <channel> :[ \"@\" / \"+\" ]          
//                            "<nick> *( \" \" [ \"@\" / \"+\" ] <nick> )     ))
std::string IrcMM::Fmt_RPL_NAMREPLY (
    const std::string   & nick,
    const std::string   & chan, 
    const std::string   & user_list ) 
{
    std::map<std::string, std::string>  tags ;
    tags["<nick>"] = nick;
    tags["<channel>"] = chan;
    tags["<user_list>"] = user_list;
    return this->getFmtMsg(RPL_NAMREPLY, tags) ;
}

// 364 RPL_LINKS,              "<mask> <server> :<hopcount> <server info>     ))
std::string IrcMM::Fmt_RPL_LINKS (
    const std::string   & mask, 
    const std::string   & host, 
    const int           & hopcount,
    const std::string   & server_info )  
{
    std::map<std::string, std::string>  tags ;
    std::stringstream ss;
    tags["<mask>"] = mask;
    tags["<server>"] = host;
    ss  << hopcount ;
    tags["<hopcount>"] = ss.str();
    tags["<server info>"] = server_info;
    return this->getFmtMsg(RPL_LINKS, tags) ;
}    

// 365 RPL_ENDOFLINKS,                         "<mask> :End of LINKS list     ))
std::string IrcMM::Fmt_RPL_ENDOFLINKS (
    const std::string   & mask ) 
{
    std::map<std::string, std::string>  tags ;
    tags["<mask>"] = mask;
    return this->getFmtMsg(RPL_ENDOFLINKS, tags) ;
}

// 366 RPL_ENDOFNAMES,                      "<nick> <channel> :End of NAMES list     ))
std::string IrcMM::Fmt_RPL_ENDOFNAMES (
    const std::string   & nick, 
    const std::string   & channel )
{
    std::map<std::string, std::string>  tags ;
     tags["<nick>"] = nick;
    tags["<channel>"] = channel;
    return this->getFmtMsg(RPL_ENDOFNAMES, tags) ;
}
 
// 367 RPL_BANLIST,                                  "<channel> <banmask>     ))
std::string IrcMM::Fmt_RPL_BANLIST (
    const std::string   & chan,
    const std::string   & banmask  )  
{
    std::map<std::string, std::string>  tags ;
    tags["<banmask>"] = banmask;
    tags["<channel>"] = chan;
    return this->getFmtMsg(RPL_BANLIST, tags) ;
}    
    
// 368 RPL_ENDOFBANLIST,              "<channel> :End of channel ban list     ))
std::string IrcMM::Fmt_RPL_ENDOFBANLIST (
    const std::string   & channel )
{
    std::map<std::string, std::string>  tags ;
    tags["<channel>"] = channel;
    return this->getFmtMsg(RPL_ENDOFBANLIST, tags) ;
}

// 369 RPL_ENDOFWHOWAS,                            "<nick> :End of WHOWAS     ))
std::string IrcMM::Fmt_RPL_ENDOFWHOWAS (
    const std::string   & nick )  
{
    std::map<std::string, std::string>  tags ;
    tags["<nick>"] = nick;
    return this->getFmtMsg(RPL_ENDOFWHOWAS, tags) ;
}

// 371 RPL_INFO,                                               ":<string>     ))
std::string IrcMM::Fmt_RPL_INFO (
    const std::string   & admin_info ) 
{
    std::map<std::string, std::string>  tags ;
    tags["<string>"] = admin_info;
    return this->getFmtMsg(RPL_INFO, tags) ;
}

// 372 RPL_MOTD,                                               ":- <text>     ))
std::string IrcMM::Fmt_RPL_MOTD (
    const std::string   & text ) 
{
    std::map<std::string, std::string>  tags ;
    tags["<text>"] = text;
    return this->getFmtMsg(RPL_MOTD, tags) ;
}

// 374 RPL_ENDOFINFO,                                  ":End of INFO list     ))
std::string IrcMM::Fmt_RPL_ENDOFINFO ()  
{
    return *this->getMsgByCode(RPL_ENDOFINFO) ;
}

// 375 RPL_MOTDSTART,                  ":- <server> Message of the day -      ))
std::string IrcMM::Fmt_RPL_MOTDSTART (
    const std::string & host ) 
{
    std::map<std::string, std::string>  tags ;
    tags["<server>"] = host;
    return this->getFmtMsg(RPL_MOTDSTART, tags) ;
}

// 376 RPL_ENDOFMOTD,                               ":End of MOTD command     ))
std::string IrcMM::Fmt_RPL_ENDOFMOTD (
    const std::string & nick )
{
    std::map<std::string, std::string>  tags ;
    tags["<nick>"] = nick;
    return this->getFmtMsg(RPL_ENDOFMOTD, tags) ;
}

// 381 RPL_YOUREOPER,                       ":You are now an IRC operator     ))
std::string IrcMM::Fmt_RPL_YOUREOPER ()  
{
    return *this->getMsgByCode(RPL_YOUREOPER) ;
}

// 382 RPL_REHASHING,                           "<config file> :Rehashing     ))
std::string IrcMM::Fmt_RPL_REHASHING (
    const std::string   & config_file ) 
{
    std::map<std::string, std::string>  tags ;
    tags["<config file>"] = config_file;
    return this->getFmtMsg(RPL_REHASHING, tags) ;
}

// 383 RPL_YOURESERVICE,                   "You are service <servicename>     ))
std::string IrcMM::Fmt_RPL_YOURESERVICE(
    const std::string & servicename ) 
{
    std::map<std::string, std::string>  tags ;
    tags["<servicename>"] = servicename;
    return this->getFmtMsg(RPL_YOURESERVICE, tags) ;
}
    
// 391 RPL_TIME,          "<server> :<string showing server's local time>     ))
std::string IrcMM::Fmt_RPL_TIME (
    const std::string & host, 
    const time_t & time ) 
{
    std::map<std::string, std::string>  tags ;
    // Convert time_t to a tm struct for local time
    tm* local_time = localtime(&time);

    // Use a character buffer to format the output
    char buffer[80];

    // Format the date and time string
    // %Y = Year with century (e.g., 2025)
    // %m = Month as a decimal number (01-12)
    // %d = Day of the month (01-31)
    // %H = Hour in 24-hour format (00-23)
    // %M = Minute (00-59)
    // %S = Second (00-59)
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", local_time);
    tags["<server>" ] = host;
    tags["<string showing server's local time>"] = buffer;
    return this->getFmtMsg(RPL_TIME, tags) ;
}    
 
// 392 RPL_USERSSTART,                             ":UserID Terminal Host     ))
std::string IrcMM::Fmt_RPL_USERSSTART ()  
{
    return *this->getMsgByCode(RPL_USERSSTART) ;
}

// 393 RPL_USERS,              ":<username> <ttyline> <const std::string>     ))
std::string IrcMM::Fmt_RPL_USERS (
    const std::string   & nick,
    const std::string   & ttyline, 
    const std::string   & host )  
{
    std::map<std::string, std::string>  tags ;
    tags["<ttyline>"] = ttyline;
    tags["<username>"] = nick;
    tags["<const std::string>"] = host;
    return this->getFmtMsg(RPL_USERS, tags) ;
}

// 394 RPL_ENDOFUSERS,                                     ":End of users     ))
std::string IrcMM::Fmt_RPL_ENDOFUSERS()  
{
    return *this->getMsgByCode(RPL_ENDOFUSERS) ;
}

// 395 RPL_NOUSERS,                                    ":Nobody logged in     ))
std::string IrcMM::Fmt_RPL_NOUSERS ()  
{
    return *this->getMsgByCode(RPL_NOUSERS) ;
}

// 401 ERR_NOSUCHNICK,                  "<nickname> :No such nick/channel     ))
std::string IrcMM::Fmt_ERR_NOSUCHNICK (
    const std::string   & nick )  
{
    std::map<std::string, std::string>  tags ;
    tags["<nickname>"] = nick;
    return this->getFmtMsg(ERR_NOSUCHNICK, tags) ;
}

// 402 ERR_NOSUCHSERVER,                   "<server name> :No such server     ))
std::string IrcMM::Fmt_ERR_NOSUCHSERVER (
    const std::string   & server_name ) 
{
    std::map<std::string, std::string>  tags ;
    tags["<server name>"] = server_name;
    return this->getFmtMsg(ERR_NOSUCHSERVER, tags) ;
}

// 403 ERR_NOSUCHCHANNEL,                "<channel name> :No such channel     ))
std::string IrcMM::Fmt_ERR_NOSUCHCHANNEL (
    const std::string   & channel ) 
{
    std::map<std::string, std::string>  tags ;
    tags["<channel name>"] = channel;
    return this->getFmtMsg(ERR_NOSUCHCHANNEL, tags) ;
}

// 404 ERR_CANNOTSENDTOCHAN,      "<channel name> :Cannot send to channel     ))
std::string IrcMM::Fmt_ERR_CANNOTSENDTOCHAN (
    const std::string   & channel ) 
{
    std::map<std::string, std::string>  tags ;
    tags["<channel name>"] = channel;
    return this->getFmtMsg(ERR_CANNOTSENDTOCHAN, tags) ;
}

// 405 ERR_TOOMANYCHANNELS, "<channel name> :You joined too many channels     ))
std::string IrcMM::Fmt_ERR_TOOMANYCHANNELS (
    const std::string   & channel ) 
{
    std::map<std::string, std::string>  tags ;
    tags["<channel name>"] = channel;
    return this->getFmtMsg(ERR_TOOMANYCHANNELS, tags) ;
}

// 406 ERR_WASNOSUCHNICK,         "<nickname> :There was no such nickname     ))
std::string IrcMM::Fmt_ERR_WASNOSUCHNICK (
    const std::string   & nick ){
    std::map<std::string, std::string>  tags ;
    tags["<nickname>"] = nick;
    return this->getFmtMsg(ERR_WASNOSUCHNICK, tags) ;
}

// 407 ERR_TOOMANYTARGETS, "<target> :<error code> recipients. <abort message>))
std::string IrcMM::Fmt_ERR_TOOMANYTARGETS (
    const std::string   & channel,
    const std::string   & error_code,
    const std::string   & abort_message )  
{
    std::map<std::string, std::string>  tags ;
    tags["<target>"] = channel;
    tags["<error code>"] = error_code;
    tags["<abort message>"] = abort_message;                
    return this->getFmtMsg(ERR_TOOMANYTARGETS, tags) ;
}    

// 408 ERR_NOSUCHSERVICE,                "<service name> :No such service     ))
std::string IrcMM::Fmt_ERR_NOSUCHSERVICE (
    const std::string   & server_name  ) 
{
    std::map<std::string, std::string>  tags ;
    tags["<service name>"] = server_name;
    return this->getFmtMsg(ERR_NOSUCHSERVICE, tags) ;
}
  
// 409 ERR_NOORIGIN,                                ":No origin specified     ))
std::string IrcMM::Fmt_ERR_NOORIGIN ()  
{
    return *this->getMsgByCode(ERR_NOORIGIN) ;
}

// 411 ERR_NORECIPIENT,                  ":No recipient given (<command>)     ))
std::string IrcMM::Fmt_ERR_NORECIPIENT (
    const std::string   & command ) 
{
    std::map<std::string, std::string>  tags ;
    tags["<command>"] = command;
    return this->getFmtMsg(ERR_NORECIPIENT, tags) ;
}

// 412 ERR_NOTEXTTOSEND,                                ":No text to send     ))
std::string IrcMM::Fmt_ERR_NOTEXTTOSEND ()  
{
    return *this->getMsgByCode(ERR_NOTEXTTOSEND) ;
}
    
// 413 ERR_NOTOPLEVEL,              "<mask> :No toplevel domain specified     ))
std::string IrcMM::Fmt_ERR_NOTOPLEVEL (
    const std::string   & mask ) 
{
    std::map<std::string, std::string>  tags ;
    tags["<mask>"] = mask;
    return this->getFmtMsg(ERR_NOTOPLEVEL, tags) ;
}

// 414 ERR_WILDTOPLEVEL,             "<mask> :Wildcard in toplevel domain     ))
std::string IrcMM::Fmt_ERR_WILDTOPLEVEL (
    const std::string   & mask )
{
    std::map<std::string, std::string>  tags ;
    tags["<mask>"] = mask;
    return this->getFmtMsg(ERR_WILDTOPLEVEL, tags) ;
}

// 415 ERR_BADMASK,                         "<mask> :Bad Server/host mask     ))
std::string IrcMM::Fmt_ERR_BADMASK (
    const std::string   & mask )
{
    std::map<std::string, std::string>  tags ;
    tags["<mask>"] = mask;
    return this->getFmtMsg(ERR_BADMASK, tags) ;
}

// 421 ERR_UNKNOWNCOMMAND,                    "<command> :Unknown command     ))
std::string IrcMM::Fmt_ERR_UNKNOWNCOMMAND (
    const std::string   & command )
{
    std::map<std::string, std::string>  tags ;
    tags["<command>"] = command;
    return this->getFmtMsg(ERR_UNKNOWNCOMMAND, tags) ;
}
       
// 422 ERR_NOMOTD,                                 ":MOTD File is missing     ))
std::string IrcMM::Fmt_ERR_NOMOTD ()  
{
    return *this->getMsgByCode(ERR_NOMOTD) ;
}

// 423 ERR_NOADMININFO,       "<server> :No administrative info available     ))
std::string IrcMM::Fmt_ERR_NOADMININFO (
    const std::string   & host ) 
{
    std::map<std::string, std::string>  tags ;
    tags["<server>"] = host;
    return this->getFmtMsg(ERR_NOADMININFO, tags) ;
}

// 424 ERR_FILEERROR,              ":File error doing <file op> on <file>     ))
std::string IrcMM::Fmt_ERR_FILEERROR (
    const std::string   & fileop, 
    const std::string   & file )  
{
    std::map<std::string, std::string>  tags ;

    tags["<file op>"] = fileop;
    tags["<file>"] = file;
    return this->getFmtMsg(ERR_FILEERROR, tags) ;
}    
    
// 431 ERR_NONICKNAMEGIVEN,                           ":No nickname given     ))
std::string IrcMM::Fmt_ERR_NONICKNAMEGIVEN ()  
{
    return *this->getMsgByCode(ERR_NONICKNAMEGIVEN) ;
}

// 416 ERR_TOOMANYMATCHES,                  "<channel> :End of NAMES list     ))
std::string IrcMM::Fmt_ERR_TOOMANYMATCHES (
    const std::string   & channel )
{
    std::map<std::string, std::string>  tags ;
    tags["<channel>"] = channel;
    return this->getFmtMsg(ERR_TOOMANYMATCHES, tags) ;
}

// 432 ERR_ERRONEUSNICKNAME
std::string IrcMM::Fmt_ERR_ERRONEUSNICKNAME (
    const std::string   & nick ) 
{
std::map<std::string, std::string>  tags ;
tags["<nick>"] = nick;
return this->getFmtMsg(ERR_ERRONEUSNICKNAME, tags) ;
}

// 433 ERR_NICKNAMEINUSE
std::string IrcMM::Fmt_ERR_NICKNAMEINUSE (
    const std::string   & nick ) 
  {
    std::map<std::string, std::string>  tags ;
    tags["<nick>"] = nick;
    return this->getFmtMsg(ERR_NICKNAMEINUSE, tags) ;
  }

// 433 ERR_ERRONEUSUSERNAME
std::string IrcMM::Fmt_ERR_ERRONEUSUSERNAME (
    const std::string   & user ) 
{
std::map<std::string, std::string>  tags ;
tags["<user>"] = user;
return this->getFmtMsg(ERR_ERRONEUSUSERNAME, tags) ;
}
// 436 ERR_NICKCOLLISION 
std::string IrcMM::Fmt_ERR_NICKCOLLISION (
    const std::string   & nick, 
    const std::string   & user, 
    const std::string   & host ) 
{
    std::map<std::string, std::string>  tags ;
    //tags[""] = ;
    tags["<nick>"] = nick;
    tags["<user>"] = user;
    tags["<host>"] = host;
    return this->getFmtMsg(ERR_NICKCOLLISION, tags) ;

}

// 437 ERR_UNAVAILRESOURCE,"<nick/channel>:Nick/channeltemporarily unavailable))
std::string IrcMM::Fmt_ERR_UNAVAILRESOURCE (
    const std::string   & nick )  
{
    std::map<std::string, std::string>  tags ;
    tags["<nick/channel>"] = nick;
    return this->getFmtMsg(ERR_UNAVAILRESOURCE, tags) ;
}

// 441 ERR_USERNOTINCHANNEL, "<nick> <channel> :They aren't on that channel   ))
std::string IrcMM::Fmt_ERR_USERNOTINCHANNEL (
    const std::string   & nick, 
    const std::string   & chan )
{
    std::map<std::string, std::string>  tags ;
    tags["<nick>"] = nick;
    tags["<channel>"] = chan;
    return this->getFmtMsg(ERR_USERNOTINCHANNEL, tags) ;
}

// 442 ERR_NOTONCHANNEL,        "<channel> :You're not on that channel        ))
std::string IrcMM::Fmt_ERR_NOTONCHANNEL (
    const std::string   & channel ) 
{
    std::map<std::string, std::string>  tags ;
    tags["<channel>"] = channel;
    return this->getFmtMsg(ERR_NOTONCHANNEL, tags) ;
}

// 443 ERR_USERONCHANNEL,        "<user> <channel> :is already on channel     ))
std::string IrcMM::Fmt_ERR_USERONCHANNEL (
    const std::string   & user, 
    const std::string   & chan )
{
    std::map<std::string, std::string>  tags ;
    tags["<user>"] = user;
    tags["<channel>"] = chan;
    return this->getFmtMsg(ERR_USERONCHANNEL, tags) ;
}

// 444 ERR_NOLOGIN,                           "<user> :User not logged in     ))
std::string IrcMM::Fmt_NOLOGIN (
    const std::string   & user )
{
    std::map<std::string, std::string>  tags ;
    tags["<user>"] = user;
    return this->getFmtMsg(ERR_NOLOGIN, tags) ;
}
    
// 445 ERR_SUMMONDISABLED,                     ":SUMMON has been disabled     ))
std::string IrcMM::Fmt_ERR_SUMMONDISABLED ()  
{
    return *this->getMsgByCode(ERR_SUMMONDISABLED) ;
}

// 446 ERR_USERSDISABLED,                      ":<user> has been disabled     ))
std::string IrcMM::Fmt_ERR_USERSDISABLED (
    const std::string   & user )
{
    std::map<std::string, std::string>  tags ;
    tags["<user>"] = user;
    return this->getFmtMsg(ERR_USERSDISABLED, tags) ;
}

// 451 ERR_NOTREGISTERED,                       ":You have not registered     ))
std::string IrcMM::Fmt_ERR_NOTREGISTERED ()  
{
    return *this->getMsgByCode(ERR_NOTREGISTERED) ;
}

// 461 ERR_NEEDMOREPARAMS,              "<command> :Not enough parameters     ))
std::string IrcMM::Fmt_ERR_NEEDMOREPARAMS (
    const std::string   & command )
{
    std::map<std::string, std::string>  tags ;
    tags["<command>"] = command;
    return this->getFmtMsg(ERR_NEEDMOREPARAMS, tags) ;
}

// 462 ERR_ALREADYREGISTRED,  ":Unauthorized command (already registered)     ))
std::string IrcMM::Fmt_ERR_ALREADYREGISTRED ()  
{
    return *this->getMsgByCode(ERR_ALREADYREGISTRED) ;
}

// 463 ERR_NOPERMFORHOST,          ":Your host isn't among the privileged     ))
std::string IrcMM::Fmt_ERR_NOPERMFORHOST ()  
{
    return *this->getMsgByCode(ERR_NOPERMFORHOST) ;
}

// 464 ERR_PASSWDMISMATCH,                           ":Password incorrect     ))
std::string IrcMM::Fmt_ERR_PASSWDMISMATCH ()  
{
    return *this->getMsgByCode(ERR_PASSWDMISMATCH) ;
}

// 465 ERR_YOUREBANNEDCREEP,            ":You are banned from this server     ))
std::string IrcMM::Fmt_ERR_YOUREBANNEDCREEP ()  
{
    return *this->getMsgByCode(ERR_YOUREBANNEDCREEP) ;
}

// 466 ERR_YOUWILLBEBANNED,        "                                          ))
std::string IrcMM::Fmt_ERR_YOUWILLBEBANNED ()  
{
    return *this->getMsgByCode(ERR_YOUWILLBEBANNED) ;
}

// 467 ERR_KEYSET,                    "<channel> :Channel key already set     ))
std::string IrcMM::Fmt_ERR_KEYSET (
    const std::string   & channel )
{
    std::map<std::string, std::string>  tags ;
    tags["<channel>"] = channel;
    return this->getFmtMsg(ERR_KEYSET, tags) ;
}

// 471 ERR_CHANNELISFULL,            "<channel> :Cannot join channel (+l)     ))
std::string IrcMM::Fmt_ERR_CHANNELISFULL (
    const std::string   & channel )
{
    std::map<std::string, std::string>  tags ;
    tags["<channel>"] = channel;
    return this->getFmtMsg(ERR_CHANNELISFULL, tags) ;
}

// 472 ERR_UNKNOWNMODE," <char> :is unknown mode char to me for <channel>     ))
std::string IrcMM::Fmt_ERR_UNKNOWNMODE (
    const char          & letra, 
    const std::string   & chan )  
{
    std::map<std::string, std::string>  tags ;

    tags["<char>"] = letra;
    tags["<channel>"] = chan;
    return this->getFmtMsg(ERR_UNKNOWNMODE, tags) ;
}    
    
// 473 ERR_INVITEONLYCHAN,           "<channel> :Cannot join channel (+i)     ))
std::string IrcMM::Fmt_ERR_INVITEONLYCHAN (
    const std::string   & channel )
{
    std::map<std::string, std::string>  tags ;
    tags["<channel>"] = channel;
    return this->getFmtMsg(ERR_INVITEONLYCHAN, tags) ;
}

// 474 ERR_BANNEDFROMCHAN,           "<channel> :Cannot join channel (+b)     ))
std::string IrcMM::Fmt_ERR_BANNEDFROMCHAN (
    const std::string   & channel )
{
    std::map<std::string, std::string>  tags ;
    tags["<channel>"] = channel;
    return this->getFmtMsg(ERR_BANNEDFROMCHAN, tags) ;
}

// 475 ERR_BADCHANNELKEY,            "<channel> :Cannot join channel (+k)     ))
std::string IrcMM::Fmt_ERR_BADCHANNELKEY (
    const std::string   & channel ) 
{
    std::map<std::string, std::string>  tags ;
    tags["<channel>"] = channel;
    return this->getFmtMsg(ERR_BADCHANNELKEY, tags) ;
}

// 476 ERR_BADCHANMASK,                      "<channel> :Bad Channel Mask     ))
std::string IrcMM::Fmt_ERR_BADCHANMASK (
    const std::string   & channel ) 
{
    std::map<std::string, std::string>  tags ;
    tags["<channel>"] = channel;
    return this->getFmtMsg(ERR_BADCHANMASK, tags) ;
}

// 477 ERR_NOCHANMODES,         "<channel> :Channel doesn't support modes     ))
std::string IrcMM::Fmt_ERR_NOCHANMODES (
    const std::string   & channel ) 
{
    std::map<std::string, std::string>  tags ;
    tags["<channel>"] = channel;
    return this->getFmtMsg(ERR_NOCHANMODES, tags) ;
}

// 478 ERR_BANLISTFULL,           "<channel> <char> :Channel list is full     ))
std::string IrcMM::Fmt_ERR_BANLISTFULL (
    const std::string   & chan, 
    const char          & letra ) 
{
    std::map<std::string, std::string>  tags ;

    tags["<char>"] = letra;
    tags["<channel>"] = chan;
    return this->getFmtMsg(ERR_BANLISTFULL, tags) ;
}    
    
// 481 ERR_NOPRIVILEGES,  ":Permission Denied- You're not an IRC operator     ))
std::string IrcMM::Fmt_RERR_NOPRIVILEGES ()  
{
    return *this->getMsgByCode(ERR_NOPRIVILEGES) ;
}

// 482 ERR_CHANOPRIVSNEEDED,      "<channel> :You're not channel operator     ))
std::string IrcMM::Fmt_ERR_CHANOPRIVSNEEDED (
    const std::string   & channel )
{
    std::map<std::string, std::string>  tags ;
    tags["<channel>"] = channel;
    return this->getFmtMsg(ERR_CHANOPRIVSNEEDED, tags) ;
}

// 483 ERR_CANTKILLSERVER,                     ":You can't kill a server!     ))
std::string IrcMM::Fmt_ERR_CANTKILLSERVER ()  
{
    return *this->getMsgByCode(ERR_CANTKILLSERVER) ;
}

// 484 ERR_RESTRICTED,                   ":Your connection is restricted!     ))
std::string IrcMM::Fmt_ERR_RESTRICTED ()  
{
    return *this->getMsgByCode(ERR_RESTRICTED) ;
}

// 485 ERR_UNIQOPPRIVSNEEDED,  ":You're not the original channel operator     ))
std::string IrcMM::Fmt_ERR_UNIQOPPRIVSNEEDED ()  
{
    return *this->getMsgByCode(ERR_UNIQOPPRIVSNEEDED) ;
}

// 491 ERR_NOOPERHOST,                         ":No O-lines for your host     ))
std::string IrcMM::Fmt_ERR_NOOPERHOST ()  
{
    return *this->getMsgByCode(ERR_NOOPERHOST) ;
}

// 501 ERR_UMODEUNKNOWNFLAG,                          ":Unknown MODE flag     ))
std::string IrcMM::Fmt_ERR_UMODEUNKNOWNFLAG ()  
{
    return *this->getMsgByCode(ERR_UMODEUNKNOWNFLAG) ;
}

// 502 ERR_USERSDONTMATCH,           ":Cannot change mode for other users     ))
std::string IrcMM::Fmt_ERR_USERSDONTMATCH () 
{
    return *this->getMsgByCode(ERR_USERSDONTMATCH) ;
}

// 503 ERR_UMODEUNTREATED        "Flag ><flag>< out of 42 FT_IRC scope"     ))
std::string IrcMM::Fmt_ERR_UMODEUNTREATED (
    const std::string & flag )
{
    std::map<std::string, std::string>  tags ;
    tags["<flag>"] = flag;
    return this->getFmtMsg(ERR_UMODEUNTREATED, tags) ;    
}

// 504 ERR_COMMANDUNTREATED  "<nick> Command <command> out of 42 FT_IRC scope"))
std::string IrcMM::Fmt_ERR_COMMANDUNTREATED (
        const std::string &    nick,           
        const std::string &    command )
{
    std::map<std::string, std::string>  tags ;
    tags["<nick>"] = nick;    
    tags["<command>"] = command;
    return this->getFmtMsg(ERR_COMMANDUNTREATED, tags) ;    
}
// 600 RPL_PRIVMSG     ":<nick_e>!<user>@<host> PRIVMSG <target> :<msg>"  ))
std::string IrcMM::Fmt_RPL_PRIVMSG(
    const std::string &    nick_e,
    const std::string &    user, 
    const std::string &    host, 
    const std::string &    target,                                 
    const std::string &    msg ) 
{
    std::map<std::string, std::string>  tags ;
    tags["<nick_e>"] = nick_e;
    tags["<user>"] = user;
    tags["<host>"] = host;
    tags["<target>"] = target;                
    tags["<msg>"] = msg;
    return this->getFmtMsg_no_prefix(RPL_PRIVMSG, tags) ;    
}


// 601 RPL_KICK ":<nick_e>!<user>@<host> KICK <chan> <nick> :<comment>"  ))
std::string IrcMM::Fmt_RPL_KICK(
    const std::string &    nick_e,
    const std::string &    user, 
    const std::string &    host, 
    const std::string &    chan,
    const std::string &    nick,                             
    const std::string &    comment ) 
{
    std::map<std::string, std::string>  tags ;
    tags["<nick_e>"] = nick_e;
    tags["<user>"] = user;
    tags["<host>"] = host;
    tags["<chan>"] = chan;    
    tags["<nick>"] = nick;                
    tags["<comment>"] = comment;
    return this->getFmtMsg_no_prefix(RPL_KICK, tags) ;    
}

// 602 RPL_PART     ":<nick_e>!<user>@<host> PART <chan> :<reason>"  ))
std::string IrcMM::Fmt_RPL_PART(
    const std::string &    nick_e,
    const std::string &    user, 
    const std::string &    host, 
    const std::string &    chan,                                 
    const std::string &    reason ) 
{
    std::map<std::string, std::string>  tags ;
    tags["<nick_e>"] = nick_e;
    tags["<user>"] = user;
    tags["<host>"] = host;
    tags["<chan>"] = chan;                
    tags["<reason>"] = reason;
    return this->getFmtMsg_no_prefix(RPL_PART, tags) ;    
}

// Método para devolver un mensaje por su código
const std::string* IrcMM::getMsgByCode(int code) const {
    std::map<int, std::string>::const_iterator it = messages_.find(code);
    if (it != messages_.end()) {
        return &(it->second);
    }
    return NULL;
}

// Método para mostrar la información del mensaje por consola
void IrcMM::printMessage(int code) const {
    const std::string* message = getMsgByCode(code);
    if (message) {
        std::cout << "--- Informacion del Mensaje ---" << std::endl;
        std::cout << "Codigo: " << code << std::endl;
        std::cout << "Texto para usuario: " << *message << std::endl;
        std::cout << "-----------------------------" << std::endl;
    } else {
        std::cout << "El codigo de error " << code << " no fue encontrado." << std::endl;
    }
}

// Nuevo método público para obtener un mensaje con sustitución de etiquetas
std::string IrcMM::getFmtMsg(
    int messageNumber,
    const std::map<std::string, std::string>& tags
) const {
    const std::string* message = getMsgByCode(messageNumber);
    if (!message) {
        std::ostringstream oss;
        oss << "Message not found for code " << messageNumber;
        return oss.str();
    }
    
    std::string formattedText = *message;
    std::map<std::string, std::string>::const_iterator it;
    for (it = tags.begin(); it != tags.end(); ++it) {
        formattedText = _substituteTag(formattedText, it->first, it->second);
    }
    std::stringstream ss;
    ss << ":ircserver " << messageNumber << " " << formattedText ;
    return ss.str();
}

std::string IrcMM::getFmtMsg_no_prefix(
    int messageNumber,
    const std::map<std::string, std::string>& tags
) const {
    const std::string* message = getMsgByCode(messageNumber);
    if (!message) {
        std::ostringstream oss;
        oss << "Message not found for code " << messageNumber;
        return oss.str();
    }
    
    std::string formattedText = *message;
    std::map<std::string, std::string>::const_iterator it;
    for (it = tags.begin(); it != tags.end(); ++it) {
        formattedText = _substituteTag(formattedText, it->first, it->second);
    }
    std::stringstream ss;
    ss << formattedText;
    return ss.str();
}

// Nuevo método privado para realizar la sustitución de una sola etiqueta
std::string IrcMM::_substituteTag(
    const std::string& text,
    const std::string& substitutionTag,
    const std::string& substitutionText
) const {
    // 1. Validar el formato de la etiqueta de sustitución
    if (substitutionTag.size() < 3 || substitutionTag[0] != '<' || 
        substitutionTag[substitutionTag.size() - 1] != '>') {
        throw std::runtime_error("Wrong Substitution Tag");
    }

    // 2. Buscar la etiqueta en el texto
    size_t pos = text.find(substitutionTag);
    if (pos == std::string::npos) {
        throw std::runtime_error("unfound Substitution Tag" + substitutionTag);
    }

    // 3. Reemplazar la etiqueta con el texto
    std::string newText = text;
    newText.replace(pos, substitutionTag.length(), substitutionText);
    pos += substitutionText.length();;
    while ((pos = newText.find(substitutionTag, pos)) != std::string::npos) {
        newText.replace(pos, substitutionTag.length(), substitutionText);
        pos += substitutionText.length();;
    }
    
    return newText;
}

// Método privado para inicializar el mapa con todos los datos
void IrcMM::initializeMessages() {
    messages_.insert(std::make_pair(RPL_WELCOME,
        " <nick> :Welcome to the Internet Relay Network <nick>!<user>@<host>"
    ));
    messages_.insert(std::make_pair(RPL_YOURHOST,
        "Your host is <servername>, running version <ver>"
    ));
    messages_.insert(std::make_pair(RPL_CREATED,
        "This server was created <date>"
    ));
    messages_.insert(std::make_pair(RPL_MYINFO,
        "<servername> <version> <available user modes> "
        "<available channel modes>"
    ));
    messages_.insert(std::make_pair(RPL_BOUNCE,
        "Try server <server name>, port <port number>"
    ));
    messages_.insert(std::make_pair(RPL_TRACELINK,
        "Link <version & debug level> <destination> "
        "<next server> V<protocol version> <link uptime in seconds> "
        "<backstream sendq> <upstream sendq>"
    ));
    messages_.insert(std::make_pair(RPL_TRACECONNECTING,
        "Try. <class> <server>"
    ));
    messages_.insert(std::make_pair(RPL_TRACEHANDSHAKE,
        "H.S. <class> <server>"
    ));
    messages_.insert(std::make_pair(RPL_TRACEUNKNOWN,
        "???? <class> [<client IP address in dot form>]"
    ));
    messages_.insert(std::make_pair(RPL_TRACEOPERATOR,
        "Oper <class> <nick>"
    ));
    messages_.insert(std::make_pair(RPL_TRACEUSER,
        "User <class> <nick>"
    ));
    messages_.insert(std::make_pair(RPL_TRACESERVER,
        "Serv <class> <integer1>S <integer2>C <server> "
        "<user>@<host> V<protocol version>"
    ));
    messages_.insert(std::make_pair(RPL_TRACERVICE,
        "Service <class> <name> <type> <active type>"
    ));
    messages_.insert(std::make_pair(RPL_TRACENEWTYPE,
        "<newtype> 0 <client name>"
    ));
    messages_.insert(std::make_pair(RPL_TRACECLASS,
        "Class <class> <count>"
    ));
    messages_.insert(std::make_pair(RPL_TRACERECONNECT,
        "Unused."
    ));
    messages_.insert(std::make_pair(RPL_STATSLINKINFO,
        "<linkname> <sendq> <sent messages> <sent Kbytes> "
        "<received messages> <received Kbytes> <time open>"
    ));
    messages_.insert(std::make_pair(RPL_STATSCOMMANDS,
        "<command> <count> <byte count> <remote count>"
    ));
    messages_.insert(std::make_pair(RPL_ENDOFSTATS,
        "<stats letter> :End of STATS report"
    ));
    messages_.insert(std::make_pair(RPL_UMODEIS,
        "<user mode string>"
    ));
    messages_.insert(std::make_pair(RPL_SERVLIST,
        "<name> <server> <mask> <type> <hopcount> <info>"
    ));
    messages_.insert(std::make_pair(RPL_SERVLISTEND,
        "<mask> <type> :End of service listing"
    ));
    messages_.insert(std::make_pair(RPL_STATSUPTIME,
        ":Server Up %d days %d:%02d:%02d"
    ));
    messages_.insert(std::make_pair(RPL_STATSOLINE,
        "O <hostmask> * <name>"
    ));
    messages_.insert(std::make_pair(RPL_LUSERCLIENT,
        ":There are <integer1> users and <integer2> services on "
        "<integer3> servers"
    ));
    messages_.insert(std::make_pair(RPL_LUSEROP,
        "<integer> :operator(s) online"
    ));
    messages_.insert(std::make_pair(RPL_LUSERUNKNOWN,
        "<integer> :unknown connection(s)"
    ));
    messages_.insert(std::make_pair(RPL_LUSERCHANNELS,
        "<integer> :channels formed"
    ));
    messages_.insert(std::make_pair(RPL_LUSERME,
        ":I have <integer1> clients and <integer2> servers"
    ));
    messages_.insert(std::make_pair(RPL_ADMINME,
        "<server> :Administrative info"
    ));
    messages_.insert(std::make_pair(RPL_ADMINLOC1,
        ":<admin info>"
    ));
    messages_.insert(std::make_pair(RPL_ADMINLOC2,
        ":<admin info>"
    ));
    messages_.insert(std::make_pair(RPL_ADMINEMAIL,
        ":<admin info>"
    ));
    messages_.insert(std::make_pair(RPL_TRACELOG,
        "File <logfile> <debug level>"
    ));
    messages_.insert(std::make_pair(RPL_TRACEEND,
        "<server name> <version & debug level> :End of TRACE"
    ));
    messages_.insert(std::make_pair(RPL_TRYAGAIN,
        "<command> :Please wait a while and try again."
    ));
    messages_.insert(std::make_pair(RPL_AWAY,
        "<nick> :<away message>"
    ));
    messages_.insert(std::make_pair(RPL_USERHOST,
        ":*1<reply> *( \" \" <reply> )"
    ));
    messages_.insert(std::make_pair(RPL_ISON,
        ":*1<nick> *( \" \" <nick> )"
    ));
    messages_.insert(std::make_pair(RPL_UNAWAY,
        ":You are no longer marked as being away"
    ));
    messages_.insert(std::make_pair(RPL_NOWAWAY,
        ":You have been marked as being away"
    ));
    messages_.insert(std::make_pair(RPL_WHOISUSER,
        "<nick> <user> <host> * :<real name>"
    ));
    messages_.insert(std::make_pair(RPL_WHOISSERVER,
        "<nick> <server> :<server info>"
    ));
    messages_.insert(std::make_pair(RPL_WHOISOPERATOR,
        "<nick> :is an IRC operator"
    ));
    messages_.insert(std::make_pair(RPL_WHOWASUSER,
        "<nick> <user> <host> * :<real name>"
    ));
    messages_.insert(std::make_pair(RPL_ENDOFWHO,
        "<nick> <chan> :End of WHO list"
    ));
    messages_.insert(std::make_pair(RPL_WHOISIDLE,
        "<nick> <integer> :seconds idle"
    ));
    messages_.insert(std::make_pair(RPL_ENDOFWHOIS,
        "<nick> :End of WHOIS list"
    ));
    messages_.insert(std::make_pair(RPL_WHOISCHANNELS,
        "<nick> :*( ( \"@\" / \"+\" ) <channel> \" \" )"
    ));
    messages_.insert(std::make_pair(RPL_LISTSTART,
        "Obsolete."
    ));
    messages_.insert(std::make_pair(RPL_LIST,
        "<nick> <channel> <# visible> :<topic>"
    ));
    messages_.insert(std::make_pair(RPL_LISTEND,
        "<nick> :End of /LIST"
    ));
    messages_.insert(std::make_pair(RPL_CHANNELMODEIS,
        "<nick> <channel> <mode> <mode params>"
    ));
    messages_.insert(std::make_pair(RPL_UNIQOPIS,
        "<channel> <nickname>"
    ));
    messages_.insert(std::make_pair(RPL_NOTOPIC,
        ": <channel> :No topic is set"
    ));
    messages_.insert(std::make_pair(RPL_TOPIC,
        "<nick> <channel> :<topic>"
    ));
    messages_.insert(std::make_pair(RPL_JOIN,
        ":<nick>!<user>@<host> JOIN :<channel>"
    ));
    messages_.insert(std::make_pair(RPL_INVITED,
        ":<hostnick>!<user>@<host> INVITE <guestnick> :<channel>"
    ));    
    messages_.insert(std::make_pair(RPL_INVITING,
        "<hostnick> <guestnick> <channel>"
    ));
    messages_.insert(std::make_pair(RPL_SUMMONING,
        "<user> :Summoning user to IRC"
    ));
    messages_.insert(std::make_pair(RPL_INVITELIST,
        "<channel> <invitemask>"
    ));
    messages_.insert(std::make_pair(RPL_ENDOFINVITELIST,
        "<channel> :End of channel invite list"
    ));
    messages_.insert(std::make_pair(RPL_EXCEPTLIST,
        "<channel> <exceptionmask>"
    ));
    messages_.insert(std::make_pair(RPL_ENDOFEXCEPTLIST,
        "<channel> :End of channel exception list"
    ));
    messages_.insert(std::make_pair(RPL_VERSION,
        "<version>.<debuglevel> <server> :<comments>"
    ));
    messages_.insert(std::make_pair(RPL_WHOREPLY,
        "<nick_e> <channel> ~<user> <host> <server> <mode><nick> <status> :<hopcount> <real name>"
    ));
    messages_.insert(std::make_pair(RPL_NAMREPLY,
        "<nick> = <channel> :<user_list>"
    ));
    messages_.insert(std::make_pair(RPL_LINKS,
        "<mask> <server> :<hopcount> <server info>"
    ));
    messages_.insert(std::make_pair(RPL_ENDOFLINKS,
        "<mask> :End of LINKS list"
    ));
    messages_.insert(std::make_pair(RPL_ENDOFNAMES,
        "<nick> <channel> :End of NAMES list"
    ));
    messages_.insert(std::make_pair(RPL_BANLIST,
        "<channel> <banmask>"
    ));
    messages_.insert(std::make_pair(RPL_ENDOFBANLIST,
        "<channel> :End of channel ban list"
    ));
    messages_.insert(std::make_pair(RPL_ENDOFWHOWAS,
        "<nick> :End of WHOWAS"
    ));
    messages_.insert(std::make_pair(RPL_INFO,
        ":<string>"
    ));
    messages_.insert(std::make_pair(RPL_MOTD,
        ":- <text>"
    ));
    messages_.insert(std::make_pair(RPL_ENDOFINFO,
        ":End of INFO list"
    ));
    messages_.insert(std::make_pair(RPL_MOTDSTART,
        ": - <server>: Have a great day!!! - "
    ));
    messages_.insert(std::make_pair(RPL_ENDOFMOTD,
        ":End of /MOTD command <nick>"
       // "<nick> :End of /MOTD command"
    ));
    messages_.insert(std::make_pair(RPL_YOUREOPER,
        ":You are now an IRC operator"
    ));
    messages_.insert(std::make_pair(RPL_REHASHING,
        "<config file> :Rehashing"
    ));
    messages_.insert(std::make_pair(RPL_YOURESERVICE,
        "You are service <servicename>"
    ));
    messages_.insert(std::make_pair(RPL_TIME,
        "<server> :<string showing server's local time>"
    ));
    messages_.insert(std::make_pair(RPL_USERSSTART,
        ":UserID Terminal Host"
    ));
    messages_.insert(std::make_pair(RPL_USERS,
        ":<username> <ttyline> <hostname>"
    ));
    messages_.insert(std::make_pair(RPL_ENDOFUSERS,
        ":End of users"
    ));
    messages_.insert(std::make_pair(RPL_NOUSERS,
        ":Nobody logged in"
    ));
    messages_.insert(std::make_pair(ERR_NOSUCHNICK,
        "<nickname> :No such nick/channel"
    ));
    messages_.insert(std::make_pair(ERR_NOSUCHSERVER,
        "<server name> :No such server"
    ));
    messages_.insert(std::make_pair(ERR_NOSUCHCHANNEL,
        "<channel name> :No such channel"
    ));
    messages_.insert(std::make_pair(ERR_CANNOTSENDTOCHAN,
        "<channel name> :Cannot send to channel"
    ));
    messages_.insert(std::make_pair(ERR_TOOMANYCHANNELS,
        "<channel name> :You have joined too many channels"
    ));
    messages_.insert(std::make_pair(ERR_WASNOSUCHNICK,
        "<nickname> :There was no such nickname"
    ));
    messages_.insert(std::make_pair(ERR_TOOMANYTARGETS,
        "<target> :<error code> recipients. <abort message>"
    ));
    messages_.insert(std::make_pair(ERR_NOSUCHSERVICE,
        "<service name> :No such service"
    ));
    messages_.insert(std::make_pair(ERR_NOORIGIN,
        ":No origin specified"
    ));
    messages_.insert(std::make_pair(ERR_NORECIPIENT,
        ":No recipient given (<command>)"
    ));
    messages_.insert(std::make_pair(ERR_NOTEXTTOSEND,
        ":No text to send"
    ));
    messages_.insert(std::make_pair(ERR_NOTOPLEVEL,
        "<mask> :No toplevel domain specified"
    ));
    messages_.insert(std::make_pair(ERR_WILDTOPLEVEL,
        "<mask> :Wildcard in toplevel domain"
    ));
    messages_.insert(std::make_pair(ERR_BADMASK,
        "<mask> :Bad Server/host mask"
    ));
    messages_.insert(std::make_pair(ERR_TOOMANYMATCHES,
        "<channel> :Output too long (try locally)"
    ));    
    messages_.insert(std::make_pair(ERR_UNKNOWNCOMMAND,
        "<command> :Unknown command"
    ));
    messages_.insert(std::make_pair(ERR_NOMOTD,
        ":MOTD File is missing"
    ));
    messages_.insert(std::make_pair(ERR_NOADMININFO,
        "<server> :No administrative info available"
    ));
    messages_.insert(std::make_pair(ERR_FILEERROR,
        ":File error doing <file op> on <file>"
    ));
    messages_.insert(std::make_pair(ERR_NONICKNAMEGIVEN,
        ":No nickname given"
    ));
    messages_.insert(std::make_pair(ERR_ERRONEUSNICKNAME,
        "<nick> :Erroneous nickname"
    ));
    messages_.insert(std::make_pair(ERR_NICKNAMEINUSE,
        "<nick> :Nickname is already in use"
    ));
    messages_.insert(std::make_pair(ERR_ERRONEUSUSERNAME,
        "<user> :Erroneous username"
    ));
    messages_.insert(std::make_pair(ERR_NICKCOLLISION,
        "<nick> :Nickname collision KILL from <user>@<host>"
    ));
    messages_.insert(std::make_pair(ERR_UNAVAILRESOURCE,
        "<nick/channel> :Nick/channel is temporarily unavailable"
    ));
    messages_.insert(std::make_pair(ERR_USERNOTINCHANNEL,
        "<nick> <channel> :They aren't on that channel"
    ));
    messages_.insert(std::make_pair(ERR_NOTONCHANNEL,
        "<channel> :You're not on that channel"
    ));
    messages_.insert(std::make_pair(ERR_USERONCHANNEL,
        "<user> <channel> :is already on channel"
    ));
    messages_.insert(std::make_pair(ERR_NOLOGIN,
        "<user> :User not logged in"
    ));
    messages_.insert(std::make_pair(ERR_SUMMONDISABLED,
        ":SUMMON has been disabled"
    ));
    messages_.insert(std::make_pair(ERR_USERSDISABLED,
        ":<user> has been disabled"
    ));
    messages_.insert(std::make_pair(ERR_NOTREGISTERED,
        ":You have not registered"
    ));
    messages_.insert(std::make_pair(ERR_NEEDMOREPARAMS,
        "<command> :Not enough parameters"
    ));
    messages_.insert(std::make_pair(ERR_ALREADYREGISTRED,
        ":Unauthorized command (already registered)"
    ));
    messages_.insert(std::make_pair(ERR_NOPERMFORHOST,
        ":Your host isn't among the privileged"
    ));
    messages_.insert(std::make_pair(ERR_PASSWDMISMATCH,
        ":Password incorrect"
    ));
    messages_.insert(std::make_pair(ERR_YOUREBANNEDCREEP,
        ":You are banned from this server"
    ));
    messages_.insert(std::make_pair(ERR_YOUWILLBEBANNED,
        ":Natalia became fed up of you"
    ));
    messages_.insert(std::make_pair(ERR_KEYSET,
        "<channel> :Channel key already set"
    ));
    messages_.insert(std::make_pair(ERR_CHANNELISFULL,
        "<channel> :Cannot join channel (+l)"
    ));
    messages_.insert(std::make_pair(ERR_UNKNOWNMODE,
        "<char> :is unknown mode char to me for <channel>"
    ));
    messages_.insert(std::make_pair(ERR_INVITEONLYCHAN,
        "<channel> :Cannot join channel (+i)"
    ));
    messages_.insert(std::make_pair(ERR_BANNEDFROMCHAN,
        "<channel> :Cannot join channel (+b)"
    ));
    messages_.insert(std::make_pair(ERR_BADCHANNELKEY,
        "<channel> :Cannot join channel (+k)"
    ));
    messages_.insert(std::make_pair(ERR_BADCHANMASK,
        "<channel> :Bad Channel Mask"
    ));
    messages_.insert(std::make_pair(ERR_NOCHANMODES,
        "<channel> :Channel doesn't support modes"
    ));
    messages_.insert(std::make_pair(ERR_BANLISTFULL,
        "<channel> <char> :Channel list is full"
    ));
    messages_.insert(std::make_pair(ERR_NOPRIVILEGES,
        ":Permission Denied- You're not an IRC operator"
    ));
    messages_.insert(std::make_pair(ERR_CHANOPRIVSNEEDED,
        "<channel> :You're not channel operator"
    ));
    messages_.insert(std::make_pair(ERR_CANTKILLSERVER,
        ":You can't kill a server!"
    ));
    messages_.insert(std::make_pair(ERR_RESTRICTED,
        ":Your connection is restricted!"
    ));
    messages_.insert(std::make_pair(ERR_UNIQOPPRIVSNEEDED,
        ":You're not the original channel operator"
    ));
    messages_.insert(std::make_pair(ERR_NOOPERHOST,
        ":No O-lines for your host"
    ));
    messages_.insert(std::make_pair(ERR_UMODEUNKNOWNFLAG,
        ":Unknown MODE flag"
    ));
    messages_.insert(std::make_pair(ERR_USERSDONTMATCH,
        ":Cannot change mode for other users"
    ));
    messages_.insert(std::make_pair(ERR_UMODEUNTREATED,
        ": User Mode ><flag>< out of 42 FT_IRC scope"
    ));
    messages_.insert(std::make_pair(ERR_COMMANDUNTREATED,
        "<nick> Command <command> out of 42 FT_IRC scope"
    ));

    messages_.insert(std::make_pair(RPL_PRIVMSG,
        ":<nick_e>!<user>@<host> PRIVMSG <target> :<msg>"
    ));    

    messages_.insert(std::make_pair(RPL_KICK,
        ":<nick_e>!<user>@<host> KICK <chan> <nick> :<comment>"
    ));    

    messages_.insert(std::make_pair(RPL_PART,
        ":<nick_e>!<user>@<host> PART <chan> :<reason>"
    ));            
}
