#include "../include/Piao.h"

Piao::Piao(std::string username, std::string senha)
    : Usuario(username, senha) {}

std::string Piao::getTipo() const {
    return "Piao";
}
