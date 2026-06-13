#ifndef VACINACAO_H
#define VACINACAO_H

#include <string>

/**
 * @brief Representa uma aplicação de vacina em um bovino.
 *
 * Guarda o nome da vacina, a data de aplicação e o lote. A validação dos dados
 * (campos obrigatórios e formato da data) é feita no construtor.
 */
class Vacinacao {
private:
    std::string nomeVacina;     ///< Nome da vacina aplicada.
    std::string dataAplicacao;  ///< Data da aplicação (DD/MM/AAAA).
    std::string lote;           ///< Lote da vacina.

    /**
     * @brief Valida o formato da data de aplicação.
     * @param data Data a validar.
     * @return true se a data tiver o formato esperado.
     */
    bool validarData(const std::string& data) const;

public:
    /**
     * @brief Cria um registro de vacinação validando os campos.
     * @param nome Nome da vacina (não pode ser vazio).
     * @param data Data de aplicação (formato DD/MM/AAAA).
     * @param lote Lote da vacina (não pode ser vazio).
     * @throws std::invalid_argument se algum campo for inválido.
     */
    Vacinacao(const std::string& nome, const std::string& data, const std::string& lote);

    std::string getNomeVacina() const;     ///< @return O nome da vacina.
    std::string getDataAplicacao() const;  ///< @return A data de aplicação.
    std::string getLote() const;           ///< @return O lote da vacina.

    /// Imprime no console os detalhes formatados da vacinação.
    void exibirDetalhes() const;
};

#endif
