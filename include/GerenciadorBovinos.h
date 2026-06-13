#ifndef GERENCIADORBOVINOS_H
#define GERENCIADORBOVINOS_H

#include <vector>
#include <map>
#include <string>
#include "Bovino.h"

class GerenciadorBovinos {
private:
    // O rebanho é indexado pelo ID para que a busca/validação seja direta e
    // não permita IDs duplicados. RelatorioSaude consome esse mapa diretamente.
    std::map<int, Bovino> rebanho;
    int proximoId;

public:
    GerenciadorBovinos();

    int gerarId();
    int cadastrarBovino(const std::string& nome, const std::string& raca, int idade);

    Bovino* buscar(int id);
    std::vector<Bovino> listar() const;
    const std::map<int, Bovino>& getRebanho() const;
};

#endif
