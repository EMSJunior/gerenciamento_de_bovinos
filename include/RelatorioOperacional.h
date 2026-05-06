#ifndef RELATORIOOPERACIONAL_H
#define RELATORIOOPERACIONAL_H

#include "GerenciadorBovinos.h"

class RelatorioOperacional {
public:
    static float mediaPesos(const GerenciadorBovinos& g);
    static int totalMortes(const GerenciadorBovinos& g);
};

#endif