#include "../include/Bovino.h"

#include <iostream>
#include <stdexcept>

// Todo bovino nasce "vivo"; o status só muda quando uma morte é registrada.
Bovino::Bovino(int id, std::string nome, std::string raca, int idade)
    : id(id), nome(nome), raca(raca), idade(idade), vivo(true) {}

int Bovino::getId() const {
    return this->id;
}

std::string Bovino::getNome() const {
    return this->nome;
}

std::string Bovino::getRaca() const {
    return this->raca;
}

int Bovino::getIdade() const {
    return this->idade;
}

bool Bovino::isVivo() const {
    return this->vivo;
}

std::vector<Vacinacao> Bovino::getVacinacoes() const {
    return this->historicoVacinacao;
}

std::vector<RegistroPeso> Bovino::getPesos() const {
    return this->pesos;
}

std::vector<RegistroMorte> Bovino::getMortes() const {
    return this->mortes;
}

void Bovino::registrarMorte(const RegistroMorte& m){
    if(!this->isVivo()){
        throw std::runtime_error("Erro: Este boi já se encontra morto.");
    }
    this->mortes.push_back(m);
    this->vivo = false;
}

void Bovino::adicionarPeso(const RegistroPeso& p){
    if(!this->isVivo()){
        throw std::runtime_error("Erro: Este boi está morto");
    }
    this->pesos.push_back(p);
}

void Bovino::adicionarVacina(const Vacinacao& vacina) {

    if(!this->isVivo()){
        throw std::runtime_error("Erro: Não é possível aplicar vacina em um bovino morto.");
    }
    this->historicoVacinacao.push_back(vacina);
}

void Bovino::exibirHistoricoVacinacao() const {
    std::cout << "\n--- Historico de Vacinacao | Bovino ID: " << this->id << " ---" << std::endl;

    if (this->historicoVacinacao.empty()) {
        std::cout << "Nenhuma vacina registrada para este animal." << std::endl;
        std::cout << "--------------------------------------------------------\n";
        return;
    }

    for (const auto& vacina : this->historicoVacinacao) {
        vacina.exibirDetalhes();
    }
    
    std::cout << "--------------------------------------------------------\n";
}
