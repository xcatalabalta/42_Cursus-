#ifndef FILEDESCRIPTOR_HPP
#define FILEDESCRIPTOR_HPP

#include <stdexcept>

class FileDescriptor {
private:
    int fd;

    // no copia (C++98)
    FileDescriptor(const FileDescriptor &);
    FileDescriptor &operator=(const FileDescriptor &);

    void setNonBlocking();

public:
    FileDescriptor() : fd(-1) {}  // constructor por defecto seguro
    explicit FileDescriptor(int fd);     // adopta y pone O_NONBLOCK
    ~FileDescriptor();

    int  get() const;
    int  release();                      // cede la propiedad (no cierra)
    void reset(int newfd);                // cierra el actual y adopta otro

    // Excepciones anidadas (estilo de tus módulos)
    class InvalidFD : public std::exception {
    public: virtual const char* what() const throw(); };
    class GetFlagsError : public std::exception {
    public: virtual const char* what() const throw(); };
    class SetFlagsError : public std::exception {
    public: virtual const char* what() const throw(); };
};

#endif // FILEDESCRIPTOR_HPP