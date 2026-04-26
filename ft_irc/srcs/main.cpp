#include "Server.hpp"
#include <iostream>
#include <cstdlib>

int main(int argc, char** argv) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <port> <password>\n";
        return 1;
    }
    int port = std::atoi(argv[1]);
    std::string pass = argv[2];

    try {
        Server s(port, pass);
        s.run();
    } catch (std::exception &e) {
        std::cerr << "Fatal: " << e.what() << "\n";
        return 1;
    }
    return 0;
}