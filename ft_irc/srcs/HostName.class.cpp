#include "HostName.class.hpp"


// Private Helper Functions
bool HostName::isShortname(const std::string& s) const {
    if (s.empty()) {
        return false;
    }
    if (!std::isalnum(static_cast<unsigned char>(s[0]))) {
        return false;
    }
    for (size_t i = 1; i < s.length(); ++i) {
        if (!std::isalnum(static_cast<unsigned char>(s[i])) && s[i] != '-') {
            return false;
        }
    }
    return true;
}

bool HostName::isHostname(const std::string& s) const {
    if (s.empty() || s.length() > 63) {
        return false;
    }

    std::string::size_type start = 0;
    std::string::size_type end = s.find('.');

    while (end != std::string::npos) {
        if (!isShortname(s.substr(start, end - start))) {
            return false;
        }
        start = end + 1;
        end = s.find('.', start);
    }
    return isShortname(s.substr(start));
}

bool HostName::isIp4addr(const std::string& s) const {
    if (s.empty()) {
        return false;
    }
    std::stringstream ss(s);
    std::string segment;
    int count = 0;
    while(std::getline(ss, segment, '.')) {
        if (segment.empty() || segment.length() > 3 || count >= 4) {
            return false;
        }
        for (size_t i = 0; i < segment.length(); ++i) {
            if (!std::isdigit(static_cast<unsigned char>(segment[i]))) {
                return false;
            }
        }
        int num = 0;
        std::stringstream seg_ss(segment);
        seg_ss >> num;
        if (num < 0 || num > 255) {
            return false;
        }
        count++;
    }
    return count == 4;
}

bool HostName::isIp6addr(const std::string& s) const {
    // This is a simplified IP6 validation and does not cover all edge cases
    // from the full RFC, but it follows the provided BNF.
    std::string temp = s;
    std::replace(temp.begin(), temp.end(), ':', ' ');
    std::stringstream ss(temp);
    std::string segment;
    int count = 0;
    while(ss >> segment) {
        if (segment.empty() || segment.length() > 4) {
            return false;
        }
        for (size_t i = 0; i < segment.length(); ++i) {
            if (!std::isxdigit(static_cast<unsigned char>(segment[i]))) {
                return false;
            }
        }
        count++;
    }
    return count == 8;
}

bool HostName::validate(const std::string& s) const {
    if (s.length() > 63) {
        return false;
    }
    return isHostname(s) || isIp4addr(s) || isIp6addr(s);
}

// Canonical methods
HostName::HostName() : _host("localhost") {
    Logger::getInstance().log("HostName::HostName localhost created.");
}

HostName::HostName(const HostName& other) : _host(other._host) {}

HostName& HostName::operator=(const HostName& other) {
    if (this != &other) {
        _host = other._host;
    }
    return *this;
}

HostName::~HostName() {
    Logger::getInstance().log("HostName::HostName "+ _host + " destroyed.");
}

// Main Constructor
HostName::HostName(const std::string& s) {
    if (!validate(s)) {
        throw std::invalid_argument("Invalid hostname format.");
    }
    _host = s;
    Logger::getInstance().log("HostName::HostName "+ _host + " Created.");
}

// Accessor Method
const std::string & HostName::get() const {
    return _host;
}

// Comparison Operators
bool HostName::operator==(const HostName& other) const {
    return _host == other._host;
}

bool HostName::operator!=(const HostName& other) const {
    return !(*this == other);
}

bool HostName::operator<(const HostName& other) const {
    return _host < other._host;
}

bool HostName::operator>(const HostName& other) const {
    return other < *this;
}

bool HostName::operator<=(const HostName& other) const {
    return !(*this > other);
}

bool HostName::operator>=(const HostName& other) const {
    return !(*this < other);
}
