#ifndef BOVINO_H
#define BOVINO_H

#include <string>
#include <vector>
#include "Vacinacao.h"
#include "RegistroPeso.h"
#include "RegistroMorte.h"

class Bovino {
private:
    int id;
    std::string nome;
    std::string raca;
    int idade;
    bool vivo;

    std::vector<Vacinacao> vacinacoes;
    std::vector<RegistroPeso> pesos;
    std::vector<RegistroMorte> mortes;

public:
    Bovino(int id, std::string nome, std::string raca, int idade);

    int getId() const;
    std::string getNome() const;
    std::string getRaca() const;
    int getIdade() const;
    bool isVivo() const;

    void adicionarVacinacao(const Vacinacao& v);
    void adicionarPeso(const RegistroPeso& p);
    void registrarMorte(const RegistroMorte& m);

    std::vector<Vacinacao> getVacinacoes() const;
    std::vector<RegistroPeso> getPesos() const;
    std::vector<RegistroMorte> getMortes() const;
};

#endif