#ifndef VACINACAO_H
#define VACINACAO_H

#include <string>

class Vacinacao {
private:
    std::string nomeVacina;
    std::string dataAplicacao;
    std::string lote;
    
    bool validarData(const std::string& data) const;

public:

    Vacinacao(const std::string& nome, const std::string& data, const std::string& lote);

    std::string getNomeVacina() const;
    std::string getDataAplicacao() const;
    std::string getLote() const;

    void exibirDetalhes() const;
};

#endif