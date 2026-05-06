#ifndef USUARIO_H
#define USUARIO_H

#include <string>

class Usuario {
protected:
    std::string username;
    std::string senha;

public:
    Usuario(std::string username, std::string senha);
    virtual ~Usuario() {}

    std::string getUsername() const;
    bool autenticar(std::string senha) const;

    virtual std::string getTipo() const = 0;
};

#endif