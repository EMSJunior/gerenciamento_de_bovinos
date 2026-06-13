#ifndef SISTEMA_H
#define SISTEMA_H

#include "Autenticador.h"
#include "GerenciadorBovinos.h"

/**
 * @brief Classe central que orquestra todo o sistema.
 *
 * Responsável por inicializar a aplicação, conduzir o login e exibir os menus
 * de acordo com o perfil do usuário autenticado, integrando os módulos de
 * autenticação, gerenciamento do rebanho, vacinação, peso, morte e relatórios.
 */
class Sistema {
private:
    Autenticador autenticador;        ///< Responsável pela autenticação dos usuários.
    GerenciadorBovinos gerenciador;   ///< Coleção e operações sobre o rebanho.
    Usuario* usuarioLogado;           ///< Usuário autenticado na sessão atual (nullptr se ninguém).

    /// Exibe e processa o menu exclusivo do Gerente.
    void menuGerente();
    /// Exibe e processa o menu exclusivo do Veterinário.
    void menuVeterinario();
    /// Exibe e processa o menu exclusivo do Peão.
    void menuPiao();
    /// Lista todos os bovinos cadastrados no rebanho.
    void listarBovinos();

public:
    /// Cria o sistema e cadastra os usuários iniciais (um de cada perfil).
    Sistema();

    /**
     * @brief Inicia o laço principal da aplicação.
     *
     * Alterna entre a tela de login e o menu do usuário até que o login seja
     * cancelado (usuário em branco), encerrando então o programa.
     */
    void iniciar();

    /// Solicita credenciais e autentica o usuário, preenchendo usuarioLogado.
    void login();

    /// Direciona o usuário autenticado para o menu correspondente ao seu perfil.
    void menu();
};

#endif
