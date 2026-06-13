#ifndef GERENCIADORBOVINOS_H
#define GERENCIADORBOVINOS_H

#include <vector>
#include <map>
#include <string>
#include "Bovino.h"

/**
 * @brief Mantém e gerencia a coleção de bovinos do rebanho.
 *
 * Centraliza o cadastro, a busca e a validação de existência dos animais. Os
 * bovinos são indexados pelo ID em um std::map, o que evita IDs duplicados e
 * torna a busca direta. O mapa é exposto para o módulo de relatórios de saúde.
 */
class GerenciadorBovinos {
private:
    std::map<int, Bovino> rebanho;  ///< Bovinos do rebanho, indexados pelo ID.
    int proximoId;                  ///< Próximo ID a ser gerado (sempre crescente).

public:
    /// Inicializa o gerenciador com o rebanho vazio e o contador de IDs em 1.
    GerenciadorBovinos();

    /**
     * @brief Gera e reserva o próximo ID único do rebanho.
     * @return Um identificador inteiro inédito.
     */
    int gerarId();

    /**
     * @brief Cadastra um novo bovino, gerando automaticamente o seu ID.
     * @param nome  Nome ou identificação do animal.
     * @param raca  Raça do animal.
     * @param idade Idade do animal em anos.
     * @return O ID gerado para o bovino recém-cadastrado.
     */
    int cadastrarBovino(const std::string& nome, const std::string& raca, int idade);

    /**
     * @brief Busca um bovino pelo ID.
     * @param id Identificador procurado.
     * @return Ponteiro para o bovino encontrado, ou nullptr se o ID não existir.
     */
    Bovino* buscar(int id);

    /// @return Uma cópia de todos os bovinos do rebanho em um vetor.
    std::vector<Bovino> listar() const;

    /// @return Referência somente leitura ao mapa interno do rebanho.
    const std::map<int, Bovino>& getRebanho() const;
};

#endif
