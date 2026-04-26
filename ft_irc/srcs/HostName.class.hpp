

#ifndef HOSTNAME_CLASS_HPP
# define HOSTNAME_CLASS_HPP

#include <string>
#include <stdexcept>
#include <cctype>
#include <algorithm>
#include <sstream>
#include "Logger.class.hpp"

// Clase de excepción personalizada
class HostNameException : public std::exception {
    public:
        HostNameException(const char* msg) : _msg(msg) {}
        virtual ~HostNameException() throw() {}
        virtual const char* what() const throw() {
            return _msg.c_str();
        }
    private:
        std::string _msg;
    };

class HostName {


public:
    // Canonical Class Form
    HostName();
    HostName(const HostName& other);
    HostName& operator=(const HostName& other);
    ~HostName();

    // Main Constructor
    explicit HostName(const std::string& s);

    // Accessor Method
    const std::string & get() const;

    // Comparison Operators
    bool operator==(const HostName& other) const;
    bool operator!=(const HostName& other) const;
    bool operator<(const HostName& other) const;
    bool operator>(const HostName& other) const;
    bool operator<=(const HostName& other) const;
    bool operator>=(const HostName& other) const;
private:
    std::string _host;

    // Validation helper functions based on BNF
    bool isShortname(const std::string& s) const;
    bool isHostname(const std::string& s) const;
    bool isIp4addr(const std::string& s) const;
    bool isIp6addr(const std::string& s) const;
    bool validate(const std::string& s) const;
};

#endif
