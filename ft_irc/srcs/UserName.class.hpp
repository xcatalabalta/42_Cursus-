#ifndef USERNAME_CLASS_HPP
#define USERNAME_CLASS_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Logger.class.hpp"

// Clase de excepción personalizada
class UserNameException : public std::exception {
public:
    UserNameException(const char* msg) : _msg(msg) {}
    virtual ~UserNameException() throw() {}
    virtual const char* what() const throw() {
        return _msg.c_str();
    }
private:
    std::string _msg;
};

class UserName {
public:
    // Forma canónica
    UserName() ;
    UserName( const UserName & other ) ;
    UserName& operator=(const UserName& other);
    ~UserName();
    
    // Métodos para la creación y validación
    UserName(const std::string& name);

    //Setters and getters
    void set( const std::string& user ) ;
    const std::string  & get() const;

    // Overloaded comparison operators
    bool operator==(const UserName& other) const;
    bool operator!=(const UserName& other) const;
    bool operator<(const UserName& other) const;
    bool operator>(const UserName& other) const;
    bool operator<=(const UserName& other) const;
    bool operator>=(const UserName& other) const;

private:
    std::string _user;
    
    // Helper functions to validate UserNames
    bool isReserved(const std::string& name);
    bool isValidLength(const std::string& name);
    bool hasValidCharacters(const std::string& name);
    bool startsWithLetter(const std::string& name);
    

};

#endif