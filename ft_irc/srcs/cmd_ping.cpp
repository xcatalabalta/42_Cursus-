#include "Parser.class.hpp"

#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <sys/time.h> // Header for gettimeofday

// Function to get the UTC timestamp formatted as YYYY-MM-DDTHH:MM:SS.mmmZ
std::string get_timestamp_ms() {
    struct timeval tv;
    struct tm* gmt_time_ptr;
    std::stringstream ss;
    char buffer_seconds[25]; // Buffer for the YYYY-MM-DDTHH:MM:SS part
    int milliseconds;

    // 1. Get the time with microsecond precision
    if (gettimeofday(&tv, NULL) != 0) {
        return "ERROR: gettimeofday failed.";
    }

    // 2. Convert the seconds part to UTC time structure
    // NOTE: gmtime is not thread-safe, but is the C++98 standard method
    gmt_time_ptr = std::gmtime(&tv.tv_sec);
    if (!gmt_time_ptr) {
        return "ERROR: Could not get GMT time.";
    }

    // 3. Format the time down to the second (YYYY-MM-DDTHH:MM:SS)
    // Using %T is common, but %H:%M:%S is maximally C++98-compliant
    std::strftime(buffer_seconds, sizeof(buffer_seconds), "%Y-%m-%dT%H:%M:%S", gmt_time_ptr);

    // 4. Calculate milliseconds and convert the whole thing to a string
    milliseconds = (int) (tv.tv_usec / 1000);

    // 5. Use stringstream for C++98 string building and padding
    ss << buffer_seconds;

    // Add decimal point and milliseconds, padding with leading zeros if needed
    ss << ".";
    
    // Add leading zeros if milliseconds < 100
    if (milliseconds < 100)
        ss << "0";
    if (milliseconds < 10)
        ss << "0";
        
    ss << milliseconds;
    
    // Add the Zulu (Z) time zone indicator
    ss << "Z";

    return ss.str();
}



void Parser::_cmd_ping(Client * client)
{
    // std::stringstream msg;
    // std::cout << "PING detectado con estos parametros" << std::endl;
    // msg << "PING detectado con estos parametros" << std::endl;
    // for (size_t i = 1; i < this->_tokens.size(); ++i) {
    //     msg << this->_tokens[i] << std::endl;
    //     std::cout << this->_tokens[i] << std::endl;
    // }
	// client->enqueueIrcMessage("PONG :"+ this->_tokens[1]);
    // return ;
    if (this->_tokens.size() > 1)
        client->enqueueIrcMessage("@time="+get_timestamp_ms() + 
        " :ircserver PONG ircserver :" + this->_tokens[1]);
    else
        client->enqueueIrcMessage("PONG :ping"); // fallback
}
