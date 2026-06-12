#include "../include/Gerente.h"

Gerente::Gerente(std::string username, std::string senha)
    : Usuario(username, senha) {}

std::string Gerente::getTipo() const {
    return "Gerente";
}
