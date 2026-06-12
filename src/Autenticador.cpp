#include "../include/Autenticador.h"

Autenticador::Autenticador() {}

// O Autenticador passa a ser o dono dos usuários cadastrados, então é ele
// quem libera essa memória ao final da execução.
Autenticador::~Autenticador() {
    for (Usuario* usuario : this->usuarios) {
        delete usuario;
    }
}

void Autenticador::adicionarUsuario(Usuario* usuario) {
    this->usuarios.push_back(usuario);
}

// Retorna o usuário autenticado ou nullptr quando o login falha. Não
// distinguimos "usuário inexistente" de "senha errada" de propósito: revelar
// qual dos dois está incorreto facilitaria descobrir nomes de usuário válidos.
Usuario* Autenticador::login(std::string username, std::string senha) {
    for (Usuario* usuario : this->usuarios) {
        if (usuario->getUsername() == username && usuario->autenticar(senha)) {
            return usuario;
        }
    }
    return nullptr;
}
