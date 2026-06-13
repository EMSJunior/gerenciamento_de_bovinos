#ifndef VETERINARIO_H
#define VETERINARIO_H

#include "Usuario.h"

/**
 * @brief Usuário com perfil de Veterinário.
 *
 * Responsável por registrar vacinações e consultar o histórico de vacinação
 * dos bovinos.
 */
class Veterinario : public Usuario {
public:
    /// Cria um veterinário com as credenciais informadas.
    Veterinario(std::string username, std::string senha);
    /// @return A string "Veterinario".
    std::string getTipo() const override;
};

#endif
