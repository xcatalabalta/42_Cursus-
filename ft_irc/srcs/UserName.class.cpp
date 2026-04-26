#include "UserName.class.hpp"


// Constructor privado para asegurar la creación controlada
//UserName::UserName(const std::string& name) : _user(name) {
//    std::cout << "UserName " << _user << " created." << std::endl;
//}

// Destructor canónico
UserName::~UserName() {
    Logger::getInstance().log("UserName::UserName " + _user + " destroyed.");
}

// Constructor de copia canónico
UserName::UserName(const UserName& other) : _user(other._user) {
    Logger::getInstance().log("UserName::UserName copied.");
}

// Operador de asignación canónico
UserName& UserName::operator=(const UserName& other) {
    if (this != &other) {
        _user = other._user;
    }
    Logger::getInstance().log("UserName::UserName assigned.");
    return *this;
}


UserName::UserName(const std::string& name){
    if (isReserved(name)) {
        throw UserNameException(("UserName >"+ name + "< is reserved.").c_str());
    }
    if (!isValidLength(name)) {
        throw UserNameException(("UserName >" + name + "< with invalid length: must be 1-8 characters.").c_str());
    }
    if (!hasValidCharacters(name)) {
        throw UserNameException(("Invalid characters in UserName >" + name +"<.").c_str());
    }
    if (!startsWithLetter(name)) {
        throw UserNameException(("UserName >"+ name +"< must start with a letter.").c_str());
    }
    this->_user = name ;
    Logger::getInstance().log("UserName::UserName " + _user + " created.");
}

// Getter para obtener el nombre
const std::string & UserName::get() const {
    return _user;
}

// Métodos de validación privados
bool UserName::isReserved(const std::string& name) {
    const std::string reservedNames[] = {"root", "bin", "daemon", "sys", "apache"};
    for (int i = 0; i < 5; ++i) {
        if (name == reservedNames[i]) {
            return true;
        }
    }
    return false;
}

bool UserName::isValidLength(const std::string& name) {
    return name.length() > 0 && name.length() <= 12;
}
/*
  user       =  1*( %x01-09 / %x0B-0C / %x0E-1F / %x21-3F / %x41-FF )
                  ; any octet except NUL, CR, LF, " " and "@"*/
bool UserName::hasValidCharacters(const std::string& name) {
    for (size_t i = 0; i < name.length(); ++i) {
        char c = name[i];
        if  (c == 0x00 || c == 0x0A || c == 0x0D || c == ' ' || c == '@') {
            return false;
        }
    }
    return true;
}

bool UserName::startsWithLetter(const std::string& n) {
    if (n.empty()) {
        return false;
    }
    return ( (n[0] >= 'a' && n[0] <= 'z') || (n[0] >= 'A' && n[0] <= 'Z' ) );
}
