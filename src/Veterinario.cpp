#include "../include/Veterinario.h"

Veterinario::Veterinario(std::string username, std::string senha)
    : Usuario(username, senha) {}

std::string Veterinario::getTipo() const {
    return "Veterinario";
}
