#ifndef VETERINARIO_H
#define VETERINARIO_H

#include "Usuario.h"

class Veterinario : public Usuario {
public:
    Veterinario(std::string username, std::string senha);
    std::string getTipo() const override;
};

#endif