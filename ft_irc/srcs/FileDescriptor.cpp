#include "FileDescriptor.hpp"
#include <unistd.h>
#include <fcntl.h>
#include <cerrno>
#include <cstring>
#include <iostream>
#include <cstdio>

// Constructor
FileDescriptor::FileDescriptor(int fd) : fd(fd) {
    std::cout << "FileDescriptor constructor called with fd=" << fd << std::endl;
    if (fd == -1)
        throw InvalidFD();

    setNonBlocking(); // garantiza NB para listen y también para clientes que adoptes
}

// Destructor
FileDescriptor::~FileDescriptor() {
    if (fd != -1)
        close(fd);
}

// Acceso al descriptor
int FileDescriptor::get() const {
    return fd;
}

// Liberar propiedad (evita que el destructor cierre el fd)
int FileDescriptor::release() {
    int old = fd;
    fd = -1;
    return old;
}

// Reasignar descriptor (cierra el anterior si existía)
void FileDescriptor::reset(int newfd) {
    if (fd != -1) {
        ::close(fd);
    }
    fd = newfd;
    if (fd != -1) {
        setNonBlocking();
    }
}

void FileDescriptor::setNonBlocking() {
    std::cout << "setNonBlocking on fd=" << fd << std::endl;
// Restricción del sujeto en macOS: SOLO esto.
#ifdef __APPLE__ 
    if (fcntl(fd, F_SETFL, O_NONBLOCK) == -1){
        perror("fcntl F_SETFL O_NONBLOCK");
        throw SetFlagsError();
    }
#else
    int flags = fcntl(fd, F_GETFL, 0);
    if (flags == -1) {
        perror("fcntl F_GETFL");
        throw GetFlagsError();
    }
    if (fcntl(fd, F_SETFL, flags | O_NONBLOCK) == -1){
        perror("fcntl F_SETFL");
        throw SetFlagsError();
    }
#endif
}

// Excepciones
const char* FileDescriptor::InvalidFD::what() const throw() {
    return "FileDescriptor: invalid file descriptor";
}

const char* FileDescriptor::GetFlagsError::what() const throw() {
    return "FileDescriptor: fcntl(F_GETFL) failed";
}

const char* FileDescriptor::SetFlagsError::what() const throw() {
    return "FileDescriptor: fcntl(F_SETFL, O_NONBLOCK) failed";
}