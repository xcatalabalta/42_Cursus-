#include "ChanName.class.hpp"


// Convierto a minúsculas
std::string toLower(const std::string& str) {
    std::string lowerStr = str;
    for (size_t i = 0; i < lowerStr.length(); ++i) {
        if (lowerStr[i] >= 'A' && lowerStr[i] <= 'Z') {
            lowerStr[i] = lowerStr[i] - 'A' + 'a';
        }
    }
    return lowerStr;
}

// Validaciones
void ChanName::validatePrefix(char prefix) {
    if (prefix != '#' && prefix != '&' && prefix != '!' && prefix != '+') {
        throw InvalidPrefixException();
    }
}

void ChanName::validateCharacters(const std::string& str) {
    for (size_t i = 0; i < str.length(); ++i) {
        char c = str[i];
        if (c == 0x00 || c == 0x07 || c == 0x0D || c == 0x0A || c == ' ' || c == ',' || c == ':') {
            throw InvalidCharacterException();
        }
    }
}

void ChanName::validateLength(const std::string& str) {
    if (str.empty() || str.length() > 50) {
        throw InvalidLengthException();
    }
}

void ChanName::validate(const std::string& name) {
    validateLength(name);
    validatePrefix(name[0]);
    validateCharacters(name);
}

// Constructores
ChanName::ChanName() : _channame("") {}

ChanName::ChanName(std::string const &name) {
    validate(name);
    _channame = toLower(name);
}

ChanName::ChanName(char prefix, std::string const &chanstring) {
    std::string tempName;
    tempName += prefix;
    tempName += chanstring;
    validate(tempName);
    _channame = toLower(tempName);
}

ChanName::ChanName(char prefix, std::string const &chanstring1, std::string const &chanstring2) {
    std::string tempName;
    tempName += prefix;
    tempName += chanstring1;
    tempName += ":";
    tempName += chanstring2;
    validate(tempName);
    _channame = toLower(tempName);
}

ChanName::ChanName(std::string const &channelid, std::string const &chanstring1, std::string const &chanstring2) {
    std::string tempName;
    tempName += channelid;
    tempName += chanstring1;
    tempName += ":";
    tempName += chanstring2;
    validate(tempName);
    _channame = toLower(tempName);
}

// Copia
ChanName::ChanName(ChanName const &src) {
    *this = src;
}

// Asignación
ChanName &ChanName::operator=(ChanName const &rhs) {
    if (this != &rhs) {
        _channame = rhs._channame;
    }
    return *this;
}

// Destructor
ChanName::~ChanName() {}

// Getter
const std::string& ChanName::get() const {
    return _channame;
}

const char & ChanName::getprefix() const {
    return _channame[0];
}