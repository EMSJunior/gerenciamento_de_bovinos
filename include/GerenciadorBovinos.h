#ifndef GERENCIADORBOVINOS_H
#define GERENCIADORBOVINOS_H

#include <vector>
#include "Bovino.h"

class GerenciadorBovinos {
private:
    std::vector<Bovino> rebanho;
    int proximoId;

public:
    GerenciadorBovinos();

    int gerarId();
    void cadastrarBovino(std::string nome, std::string raca, int idade);

    Bovino* buscar(int id);
    std::vector<Bovino> listar() const;
};

#endif