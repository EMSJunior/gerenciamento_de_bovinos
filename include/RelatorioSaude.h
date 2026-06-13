#ifndef RELATORIO_SAUDE_H
#define RELATORIO_SAUDE_H

#include <map>
#include "Bovino.h"

/**
 * @brief Gera os relatórios de saúde do rebanho.
 *
 * Percorre os bovinos e extrai o histórico de vacinação, tanto de forma geral
 * (todo o rebanho) quanto individual (por ID de animal).
 */
class RelatorioSaude {
public:
    RelatorioSaude() = default;

    /**
     * @brief Exibe o histórico de vacinação de todo o rebanho.
     * @param rebanho Mapa de bovinos indexado por ID.
     */
    void gerarRelatorioGeral(const std::map<int, Bovino>& rebanho) const;

    /**
     * @brief Exibe o histórico de vacinação de um único animal.
     * @param rebanho  Mapa de bovinos indexado por ID.
     * @param idBovino ID do animal a consultar.
     */
    void exibirHistoricoAnimal(const std::map<int, Bovino>& rebanho, int idBovino) const;
};

#endif
