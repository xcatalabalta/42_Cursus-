#include "Logger.class.hpp"


// Inicialización de la única instancia
Logger* Logger::_instance = 0;

// Constructor privado que abre el archivo de registro
Logger::Logger() {
    _logFile.open("ft_irc_log.txt", std::ios::out);  //app = append; out = new
    if (!_logFile.is_open()) {
        std::cerr << "Error: Could not open log file." << std::endl;
    }
}

// Destructor para cerrar el archivo al finalizar
Logger::~Logger() {
    if (_logFile.is_open()) {
        _logFile.close();
    }
}

// Constructor de copia y operador de asignación son privados y vacíos,
// para evitar que la clase sea copiada.
Logger::Logger(const Logger& other) {
    (void)other;
}

Logger& Logger::operator=(const Logger& other) {
    (void)other;
    return *this;
}

// Método estático para obtener la única instancia
Logger& Logger::getInstance() {
    if (_instance == 0) {
        _instance = new Logger();
    }
    return *_instance;
}

// Método para escribir un mensaje en el log
void Logger::log(const std::string& message) {
    if (_logFile.is_open()) {
        _logFile << message << std::endl;
    } else {
        std::cerr << "Error: Log file is not open." << std::endl;
    }
}