#ifndef USUARIO_H
#define USUARIO_H

#include <string>

/**
 * @brief Classe base abstrata para os usuários do sistema.
 *
 * Armazena as credenciais (login e senha) e define o contrato de autenticação.
 * Cada subclasse (Gerente, Veterinario, Piao) representa um perfil de acesso
 * distinto, identificado por getTipo().
 */
class Usuario {
protected:
    std::string username;  ///< Nome de login do usuário.
    std::string senha;     ///< Senha do usuário (nunca exposta por getter).

public:
    /**
     * @brief Cria um usuário com as credenciais informadas.
     * @param username Nome de login.
     * @param senha    Senha de acesso.
     */
    Usuario(std::string username, std::string senha);
    virtual ~Usuario() {}

    /// @return O nome de login do usuário.
    std::string getUsername() const;

    /**
     * @brief Verifica se a senha fornecida confere.
     * @param senha Palpite de senha.
     * @return true se a senha estiver correta.
     */
    bool autenticar(std::string senha) const;

    /// @return O nome do perfil ("Gerente", "Veterinario" ou "Piao").
    virtual std::string getTipo() const = 0;
};

#endif
