#ifndef SISTEMA_H
#define SISTEMA_H

#include "Autenticador.h"
#include "GerenciadorBovinos.h"

class Sistema {
private:
    Autenticador autenticador;
    GerenciadorBovinos gerenciador;
    Usuario* usuarioLogado;

    // Menus específicos de cada perfil, acionados a partir de menu().
    void menuGerente();
    void menuVeterinario();
    void menuPiao();
    void listarBovinos();

public:
    Sistema();

    void iniciar();
    void login();
    void menu();
};

#endif