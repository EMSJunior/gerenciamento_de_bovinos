#ifndef AUTENTICADOR_H
#define AUTENTICADOR_H

#include <vector>
#include <string>
#include "Usuario.h"

class Autenticador {
private:
    std::vector<Usuario*> usuarios;

public:
    Autenticador();
    ~Autenticador();

    void adicionarUsuario(Usuario* usuario);
    Usuario* login(std::string username, std::string senha);
};

#endif