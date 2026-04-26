#ifndef CHANNELNAME_CLASS_HPP
# define CHANNELNAME_CLASS_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <algorithm>

class ChanName {

public:
    class InvalidPrefixException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Invalid prefix. A channel name must start with '#', '&', '!', or '+'.";
        }
    };

    class InvalidCharacterException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Invalid characters in the channel name. A channel name cannot contain NUL, BELL, CR, LF, ' ', ',', or ':'.";
        }
    };

    class InvalidLengthException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Channel name length is invalid. It must be between 1 and 50 characters.";
        }
    };

    ChanName();
    ChanName(std::string const &name);
    ChanName(char prefix, std::string const &chanstring);
    ChanName(char prefix, std::string const &chanstring1, std::string const &chanstring2);
    ChanName(std::string const &channelid, std::string const &chanstring1, std::string const &chanstring2) ;
    ChanName(ChanName const &src);
    ~ChanName();

    ChanName &operator=(ChanName const &rhs);

    const std::string& get() const;
    const char & getprefix() const;

private:
    std::string _channame;

    static void validate(const std::string& name);
    static void validatePrefix(char prefix);
    static void validateCharacters(const std::string& str);
    static void validateLength(const std::string& str);
};

#endif