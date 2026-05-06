#ifndef SISTEMA_H
#define SISTEMA_H

#include "Autenticador.h"
#include "GerenciadorBovinos.h"

class Sistema {
private:
    Autenticador autenticador;
    GerenciadorBovinos gerenciador;
    Usuario* usuarioLogado;

public:
    Sistema();

    void iniciar();
    void login();
    void menu();
};

#endif