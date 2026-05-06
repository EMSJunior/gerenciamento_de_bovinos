#ifndef RELATORIOSAUDE_H
#define RELATORIOSAUDE_H

#include "GerenciadorBovinos.h"

class RelatorioSaude {
public:
    static int totalVacinacoes(const GerenciadorBovinos& g);
    static void listarHistoricoVacinas(const GerenciadorBovinos& g, int idBovino);
};

#endif