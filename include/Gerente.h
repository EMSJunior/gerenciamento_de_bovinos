#ifndef GERENTE_H
#define GERENTE_H

#include "Usuario.h"

class Gerente : public Usuario {
public:
    Gerente(std::string username, std::string senha);
    std::string getTipo() const override;
};

#endif