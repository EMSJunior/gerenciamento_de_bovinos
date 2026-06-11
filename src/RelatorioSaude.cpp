#include "../include/RelatorioSaude.h"
#include <iostream>

void RelatorioSaude::gerarRelatorioGeral(const std::map<int, Bovino>& rebanho) const {
    std::cout << "\n========================================================" << std::endl;
    std::cout << "               RELATÓRIO GERAL DE SAÚDE                 " << std::endl;
    std::cout << "========================================================\n" << std::endl;

    if (rebanho.empty()) {
        std::cout << "O rebanho está vazio. Nenhum dado de saúde para exibir." << std::endl;
        std::cout << "========================================================\n";
        return;
    }

    for (const auto& par : rebanho) {

        par.second.exibirHistoricoVacinacao();
    }
    
    std::cout << "========================================================\n";
}

void RelatorioSaude::exibirHistoricoAnimal(const std::map<int, Bovino>& rebanho, int idBovino) const {

    auto it = rebanho.find(idBovino);

    if (it != rebanho.end()) {
        std::cout << "\nBuscando registros do animal ID: " << idBovino << "..." << std::endl;

        it->second.exibirHistoricoVacinacao();
    } else {
        std::cout << "\nErro: Bovino com ID " << idBovino << " não encontrado no sistema." << std::endl;
    }
}