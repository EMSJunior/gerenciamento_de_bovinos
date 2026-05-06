#ifndef PIAO_H
#define PIAO_H

#include "Usuario.h"

class Piao : public Usuario {
public:
    Piao(std::string username, std::string senha);
    std::string getTipo() const override;
};

#endif