#include "../include/Usuario.h"

Usuario::Usuario(std::string username, std::string senha)
    : username(username), senha(senha) {}

std::string Usuario::getUsername() const {
    return this->username;
}

// A senha nunca é exposta por um getter: quem quiser conferir o acesso
// precisa fornecer um palpite e deixar a própria classe comparar.
bool Usuario::autenticar(std::string senha) const {
    return this->senha == senha;
}
