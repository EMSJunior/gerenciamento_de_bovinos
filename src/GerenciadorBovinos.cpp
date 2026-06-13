#include "../include/GerenciadorBovinos.h"

// Os IDs começam em 1 e são sempre crescentes, garantindo unicidade mesmo que
// um bovino seja removido no futuro.
GerenciadorBovinos::GerenciadorBovinos() : proximoId(1) {}

int GerenciadorBovinos::gerarId() {
    return this->proximoId++;
}

// Cria o bovino com um ID gerado pelo próprio sistema (o usuário não escolhe o
// ID, o que evita duplicidade) e devolve esse ID para feedback no menu.
int GerenciadorBovinos::cadastrarBovino(const std::string& nome, const std::string& raca, int idade) {
    int id = gerarId();
    this->rebanho.emplace(id, Bovino(id, nome, raca, idade));
    return id;
}

// Retorna um ponteiro para o bovino dentro do rebanho (permite alteração) ou
// nullptr quando o ID não existe. Programação defensiva contra IDs inválidos.
Bovino* GerenciadorBovinos::buscar(int id) {
    auto it = this->rebanho.find(id);
    if (it == this->rebanho.end()) {
        return nullptr;
    }
    return &it->second;
}

std::vector<Bovino> GerenciadorBovinos::listar() const {
    std::vector<Bovino> lista;
    for (const auto& par : this->rebanho) {
        lista.push_back(par.second);
    }
    return lista;
}

const std::map<int, Bovino>& GerenciadorBovinos::getRebanho() const {
    return this->rebanho;
}
