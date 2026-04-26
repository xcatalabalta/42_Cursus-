#include "NickName.class.hpp"


// Private helper functions
bool NickName::isValidCharacter(char c, bool isFirstChar) const {
    if (isFirstChar) {
        return std::isalpha(static_cast<unsigned char>(c)) || (c >= '[' && c <= '`') || (c >= '{' && c <= '}');
    } else {
        return std::isalpha(static_cast<unsigned char>(c)) || std::isdigit(static_cast<unsigned char>(c)) || (c >= '[' && c <= '`') || (c >= '{' && c <= '}') || c == '-';
    }
}

void NickName::validate(const std::string& name) const {
    if (name.length() > 12) {
        int l = name.length();
        std::cout << "[DEBUG]: el cliente tiene " << l << " caracteres " << name << "\n"; 
        throw std::invalid_argument("NickName debe tener 12 o menos caracteres.");
    }
    if (!isValidCharacter(name[0], true)) {
        throw std::invalid_argument("Nickname's initial must be a letter or special character.");
    }
    for (size_t i = 1; i < name.length(); ++i) {
        if (!isValidCharacter(name[i], false)) {
            throw std::invalid_argument("After the first character, subsequent characters must be a letter, digit, special character, or dash.");
        }
    }
}

// Functor methods
char NickName::NormalizedCharEqual::normalize(char c) const {
    switch (c) {
        case '{': return '[';
        case '}': return ']';
        case '|': return '\\';
        case '^': return '~';
        default: return c;
    }
}
bool NickName::NormalizedCharEqual::operator()(char a, char b) const {
    return normalize(a) == normalize(b);
}

char NickName::NormalizedCharLess::normalize(char c) const {
    switch (c) {
        case '{': return '[';
        case '}': return ']';
        case '|': return '\\';
        case '^': return '~';
        default: return c;
    }
}
bool NickName::NormalizedCharLess::operator()(char a, char b) const {
    return normalize(a) < normalize(b);
}

// Canonical methods
NickName::NickName() : _nick("Undefined") {}

NickName::NickName(const NickName& other) {
    *this = other;
}

NickName& NickName::operator=(const NickName& other) {
    if (this != &other) {
        this->_nick = other._nick;
    }
    return *this;
}

NickName::~NickName() {
    Logger::getInstance().log("NickName::NickName " + _nick + " Destroyed.");
   
}

// Constructor principal
NickName::NickName(const std::string& name) {
    validate(name);
    _nick = name;
    Logger::getInstance().log("NickName::NickName "+ _nick + " created.");
}

// Public methods
const std::string & NickName::get() const {
    return _nick;
}

// Overloaded comparison operators
bool NickName::operator==(const NickName& other) const {
    return std::equal(_nick.begin(), _nick.end(), other._nick.begin(), NormalizedCharEqual());
}

bool NickName::operator!=(const NickName& other) const {
    return !(*this == other);
}

bool NickName::operator<(const NickName& other) const {
    return std::lexicographical_compare(_nick.begin(), _nick.end(), other._nick.begin(), other._nick.end(), NormalizedCharLess());
}

bool NickName::operator>(const NickName& other) const {
    return other < *this;
}

bool NickName::operator<=(const NickName& other) const {
    return !(*this > other);
}

bool NickName::operator>=(const NickName& other) const {
    return !(*this < other);
}
