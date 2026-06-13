#ifndef AUTENTICADOR_H
#define AUTENTICADOR_H

#include <vector>
#include <string>
#include "Usuario.h"

/**
 * @brief Gerencia os usuários cadastrados e valida o login.
 *
 * É o dono da memória dos usuários: os ponteiros adicionados são liberados no
 * destrutor. O login não distingue "usuário inexistente" de "senha errada",
 * por segurança.
 */
class Autenticador {
private:
    std::vector<Usuario*> usuarios;  ///< Usuários cadastrados no sistema.

public:
    /// Cria um autenticador sem usuários.
    Autenticador();
    /// Libera a memória de todos os usuários cadastrados.
    ~Autenticador();

    /**
     * @brief Adiciona um usuário ao sistema (assume a posse do ponteiro).
     * @param usuario Ponteiro para o usuário a ser cadastrado.
     */
    void adicionarUsuario(Usuario* usuario);

    /**
     * @brief Tenta autenticar um usuário pelas credenciais.
     * @param username Nome de login.
     * @param senha    Senha informada.
     * @return Ponteiro para o usuário autenticado, ou nullptr em caso de falha.
     */
    Usuario* login(std::string username, std::string senha);
};

#endif
