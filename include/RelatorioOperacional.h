#ifndef RELATORIOOPERACIONAL_H
#define RELATORIOOPERACIONAL_H

#include "GerenciadorBovinos.h"

/**
 * @brief Relatórios operacionais consolidados do rebanho.
 *
 * Fornece indicadores de produtividade e perdas: peso médio dos animais vivos
 * e total de mortes registradas. Os métodos são estáticos (não dependem de
 * estado interno).
 */
class RelatorioOperacional {
public:
    /**
     * @brief Calcula o peso médio dos animais vivos (última pesagem de cada um).
     * @param g Gerenciador com o rebanho a analisar.
     * @return O peso médio em kg, ou 0 se nenhum animal vivo tiver pesagem.
     */
    static float mediaPesos(const GerenciadorBovinos& g);

    /**
     * @brief Conta o total de bovinos mortos no rebanho.
     * @param g Gerenciador com o rebanho a analisar.
     * @return O número de animais marcados como mortos.
     */
    static int totalMortes(const GerenciadorBovinos& g);
};

#endif
