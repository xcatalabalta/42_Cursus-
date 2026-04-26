#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <fstream>
#include <string>
#include <iostream>

class Logger {

public:
    // Forma canónica
    ~Logger();
    
    // Métodos para el patrón Singleton
    static Logger& getInstance();
    void log(const std::string& message);

private:
    // Puntos de entrada para la forma canónica, hechos privados
    // para cumplir con el patrón Singleton.
    Logger();
    Logger(const Logger& other);
    Logger& operator=(const Logger& other);
    
    // Miembro estático para la única instancia
    static Logger* _instance;
    std::ofstream _logFile;
};

#endif