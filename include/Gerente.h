#ifndef GERENTE_H
#define GERENTE_H

#include "Usuario.h"

/**
 * @brief Usuário com perfil de Gerente.
 *
 * Tem acesso ao cadastro de bovinos, listagem do rebanho e aos relatórios de
 * saúde e operacionais.
 */
class Gerente : public Usuario {
public:
    /// Cria um gerente com as credenciais informadas.
    Gerente(std::string username, std::string senha);
    /// @return A string "Gerente".
    std::string getTipo() const override;
};

#endif
