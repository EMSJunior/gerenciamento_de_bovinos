#include "../include/Bovino.h"

#include <iostream>




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
