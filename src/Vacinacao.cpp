#include "../include/Vacinacao.h"
#include <iostream>
#include <stdexcept>

// Implementação da validação interna (Método Privado)
bool Vacinacao::validarData(const std::string& data) const {

    return data.length() == 10;
}

Vacinacao::Vacinacao(const std::string& nome, const std::string& data, const std::string& lote) {
    // 1. Validar se os campos obrigatórios não estão vazios
    if (nome.empty() || lote.empty()) {
        throw std::invalid_argument("Erro: O nome da vacina e o lote não podem ficar em branco.");
    }

    if (!validarData(data)) {
        throw std::invalid_argument("Erro: Formato de data inválido. Utilize o padrao DD/MM/AAAA.");
    }

    this->nomeVacina = nome;
    this->dataAplicacao = data;
    this->lote = lote;
}

std::string Vacinacao::getNomeVacina() const {
    return this->nomeVacina;
}

std::string Vacinacao::getDataAplicacao() const {
    return this->dataAplicacao;
}

std::string Vacinacao::getLote() const {
    return this->lote;
}

// Método para exibir os dados no relatório
void Vacinacao::exibirDetalhes() const {
    std::cout << "[Vacina] " << this->nomeVacina 
              << " | Data: " << this->dataAplicacao 
              << " | Lote: " << this->lote << std::endl;
}