#include "../include/Bovino.h"

#include <iostream>
#include <stdexcept>



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
