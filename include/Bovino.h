#ifndef BOVINO_H
#define BOVINO_H

#include <string>
#include <vector>
#include "Vacinacao.h"
#include "RegistroPeso.h"
#include "RegistroMorte.h"

/**
 * @brief Representa um animal do rebanho e todo o seu histórico.
 *
 * Além dos dados básicos (ID, nome, raça, idade e status de vida), cada bovino
 * mantém internamente suas próprias listas de vacinações, pesagens e registros
 * de morte. Operações que alteram o histórico verificam se o animal está vivo.
 */
class Bovino {
private:
    int id;                ///< Identificador único do animal.
    std::string nome;      ///< Nome ou identificação do animal.
    std::string raca;      ///< Raça do animal.
    int idade;             ///< Idade em anos.
    bool vivo;             ///< true enquanto o animal está vivo.

    std::vector<Vacinacao> historicoVacinacao;  ///< Vacinas aplicadas.
    std::vector<RegistroPeso> pesos;            ///< Pesagens registradas.
    std::vector<RegistroMorte> mortes;          ///< Registro(s) de morte.

public:
    /**
     * @brief Cria um bovino vivo com os dados informados.
     * @param id    Identificador único.
     * @param nome  Nome/identificação.
     * @param raca  Raça.
     * @param idade Idade em anos.
     */
    Bovino(int id, std::string nome, std::string raca, int idade);

    int getId() const;          ///< @return O ID do animal.
    std::string getNome() const;///< @return O nome do animal.
    std::string getRaca() const;///< @return A raça do animal.
    int getIdade() const;       ///< @return A idade do animal.
    bool isVivo() const;        ///< @return true se o animal está vivo.

    /// Adiciona uma vacinação. @throws std::runtime_error se o animal estiver morto.
    void adicionarVacina(const Vacinacao& v);
    /// Adiciona uma pesagem. @throws std::runtime_error se o animal estiver morto.
    void adicionarPeso(const RegistroPeso& p);
    /// Registra a morte do animal. @throws std::runtime_error se já estiver morto.
    void registrarMorte(const RegistroMorte& m);

    std::vector<Vacinacao> getVacinacoes() const;  ///< @return Cópia do histórico de vacinas.
    std::vector<RegistroPeso> getPesos() const;    ///< @return Cópia do histórico de pesos.
    std::vector<RegistroMorte> getMortes() const;  ///< @return Cópia dos registros de morte.

    /// Imprime no console o histórico completo de vacinação do animal.
    void exibirHistoricoVacinacao() const;
};

#endif
