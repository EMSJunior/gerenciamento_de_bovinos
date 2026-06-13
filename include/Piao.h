#ifndef PIAO_H
#define PIAO_H

#include "Usuario.h"

/**
 * @brief Usuário com perfil de Peão.
 *
 * Responsável por registrar o peso e a morte dos bovinos do rebanho.
 */
class Piao : public Usuario {
public:
    /// Cria um peão com as credenciais informadas.
    Piao(std::string username, std::string senha);
    /// @return A string "Piao".
    std::string getTipo() const override;
};

#endif
