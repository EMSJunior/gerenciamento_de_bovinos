#ifndef RELATORIO_SAUDE_H
#define RELATORIO_SAUDE_H

#include <map>
#include "Bovino.h"

class RelatorioSaude {
public:

    RelatorioSaude() = default;

    void gerarRelatorioGeral(const std::map<int, Bovino>& rebanho) const;

    void exibirHistoricoAnimal(const std::map<int, Bovino>& rebanho, int idBovino) const;
};

#endif