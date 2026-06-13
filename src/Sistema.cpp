#include "../include/Sistema.h"

#include "../include/Gerente.h"
#include "../include/Veterinario.h"
#include "../include/Piao.h"
#include "../include/RelatorioSaude.h"
#include "../include/RelatorioOperacional.h"
#include "../include/Vacinacao.h"
#include "../include/RegistroPeso.h"
#include "../include/RegistroMorte.h"

#include <iostream>
#include <limits>
#include <string>

// ---------------------------------------------------------------------------
// Funções utilitárias de leitura (programação defensiva)
// ---------------------------------------------------------------------------

// Lê um número inteiro do teclado tratando entradas inválidas (texto, vazio).
// Repete a pergunta até receber um inteiro válido.
static int lerInteiro(const std::string& prompt) {
    int valor;
    while (true) {
        std::cout << prompt;
        if (std::cin >> valor) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return valor;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Entrada invalida. Digite um numero.\n";
    }
}

// Lê um número real (peso) tratando entradas inválidas. Repete até ser válido.
static float lerFloat(const std::string& prompt) {
    float valor;
    while (true) {
        std::cout << prompt;
        if (std::cin >> valor) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return valor;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Entrada invalida. Digite um numero.\n";
    }
}

// Lê uma linha de texto não vazia.
static std::string lerTexto(const std::string& prompt) {
    std::string linha;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, linha);
        if (!linha.empty()) {
            return linha;
        }
        std::cout << "O campo nao pode ficar em branco.\n";
    }
}

// ---------------------------------------------------------------------------
// Construção do sistema
// ---------------------------------------------------------------------------

Sistema::Sistema() : usuarioLogado(nullptr) {
    // Usuários iniciais do sistema (um de cada perfil). O Autenticador assume a
    // posse dessa memória e a libera no seu destrutor.
    this->autenticador.adicionarUsuario(new Gerente("ger1", "123"));
    this->autenticador.adicionarUsuario(new Veterinario("vet1", "123"));
    this->autenticador.adicionarUsuario(new Piao("peao1", "123"));
}

// ---------------------------------------------------------------------------
// Fluxo principal
// ---------------------------------------------------------------------------

void Sistema::iniciar() {
    std::cout << "==============================================\n";
    std::cout << "   SISTEMA DE GERENCIAMENTO DE BOVINOS\n";
    std::cout << "==============================================\n";

    while (true) {
        login();

        if (this->usuarioLogado == nullptr) {
            // Login cancelado pelo usuário -> encerra o programa.
            break;
        }

        menu();
        this->usuarioLogado = nullptr; // logout: volta para a tela de login
    }

    std::cout << "\nSistema encerrado. Ate logo!\n";
}

void Sistema::login() {
    while (this->usuarioLogado == nullptr) {
        std::cout << "\n--- LOGIN ---\n";
        std::cout << "(deixe o usuario em branco para sair)\n";

        std::cout << "Usuario: ";
        std::string username;
        std::getline(std::cin, username);

        if (username.empty()) {
            return; // sinaliza saída do sistema
        }

        std::cout << "Senha: ";
        std::string senha;
        std::getline(std::cin, senha);

        Usuario* usuario = this->autenticador.login(username, senha);
        if (usuario != nullptr) {
            this->usuarioLogado = usuario;
            std::cout << "\nBem-vindo, " << usuario->getUsername()
                      << " [" << usuario->getTipo() << "]\n";
        } else {
            std::cout << "\nUsuario ou senha invalidos. Tente novamente.\n";
        }
    }
}

void Sistema::menu() {
    std::string tipo = this->usuarioLogado->getTipo();

    if (tipo == "Gerente") {
        menuGerente();
    } else if (tipo == "Veterinario") {
        menuVeterinario();
    } else if (tipo == "Piao") {
        menuPiao();
    } else {
        std::cout << "Perfil sem menu definido.\n";
    }
}

// ---------------------------------------------------------------------------
// Menus por perfil
// ---------------------------------------------------------------------------

void Sistema::menuGerente() {
    while (true) {
        std::cout << "\n========== MENU GERENTE ==========\n";
        std::cout << "1 - Cadastrar bovino\n";
        std::cout << "2 - Listar bovinos\n";
        std::cout << "3 - Relatorio geral de saude\n";
        std::cout << "4 - Historico de saude de um animal\n";
        std::cout << "5 - Relatorios operacionais (peso / mortalidade)\n";
        std::cout << "0 - Logout\n";
        int opcao = lerInteiro("Opcao: ");

        if (opcao == 0) {
            return;
        } else if (opcao == 1) {
            std::string nome = lerTexto("Nome/identificacao do bovino: ");
            std::string raca = lerTexto("Raca: ");
            int idade = lerInteiro("Idade (anos): ");
            int id = this->gerenciador.cadastrarBovino(nome, raca, idade);
            std::cout << "Bovino cadastrado com sucesso! ID gerado: " << id << "\n";
        } else if (opcao == 2) {
            listarBovinos();
        } else if (opcao == 3) {
            RelatorioSaude relatorio;
            relatorio.gerarRelatorioGeral(this->gerenciador.getRebanho());
        } else if (opcao == 4) {
            int id = lerInteiro("ID do bovino: ");
            RelatorioSaude relatorio;
            relatorio.exibirHistoricoAnimal(this->gerenciador.getRebanho(), id);
        } else if (opcao == 5) {
            float media = RelatorioOperacional::mediaPesos(this->gerenciador);
            int mortes = RelatorioOperacional::totalMortes(this->gerenciador);
            std::cout << "\n--- Relatorio Operacional ---\n";
            std::cout << "Media de peso (animais vivos): " << media << " kg\n";
            std::cout << "Total de mortes registradas: " << mortes << "\n";
        } else {
            std::cout << "Opcao invalida.\n";
        }
    }
}

void Sistema::menuVeterinario() {
    while (true) {
        std::cout << "\n========== MENU VETERINARIO ==========\n";
        std::cout << "1 - Registrar vacinacao\n";
        std::cout << "2 - Ver historico de vacinacao de um bovino\n";
        std::cout << "0 - Logout\n";
        int opcao = lerInteiro("Opcao: ");

        if (opcao == 0) {
            return;
        } else if (opcao == 1) {
            int id = lerInteiro("ID do bovino: ");
            Bovino* bovino = this->gerenciador.buscar(id);
            if (bovino == nullptr) {
                std::cout << "Bovino com ID " << id << " nao encontrado.\n";
                continue;
            }
            std::string nome = lerTexto("Nome da vacina: ");
            std::string data = lerTexto("Data de aplicacao (DD/MM/AAAA): ");
            std::string lote = lerTexto("Lote: ");
            try {
                Vacinacao vacina(nome, data, lote);
                bovino->adicionarVacina(vacina);
                std::cout << "Vacinacao registrada com sucesso!\n";
            } catch (const std::exception& e) {
                std::cout << e.what() << "\n";
            }
        } else if (opcao == 2) {
            int id = lerInteiro("ID do bovino: ");
            Bovino* bovino = this->gerenciador.buscar(id);
            if (bovino == nullptr) {
                std::cout << "Bovino com ID " << id << " nao encontrado.\n";
                continue;
            }
            bovino->exibirHistoricoVacinacao();
        } else {
            std::cout << "Opcao invalida.\n";
        }
    }
}

void Sistema::menuPiao() {
    while (true) {
        std::cout << "\n========== MENU PEAO ==========\n";
        std::cout << "1 - Registrar peso\n";
        std::cout << "2 - Registrar morte\n";
        std::cout << "0 - Logout\n";
        int opcao = lerInteiro("Opcao: ");

        if (opcao == 0) {
            return;
        } else if (opcao == 1) {
            int id = lerInteiro("ID do bovino: ");
            Bovino* bovino = this->gerenciador.buscar(id);
            if (bovino == nullptr) {
                std::cout << "Bovino com ID " << id << " nao encontrado.\n";
                continue;
            }
            float peso = lerFloat("Peso (kg): ");
            std::string data = lerTexto("Data (DD/MM/AAAA): ");
            try {
                bovino->adicionarPeso(RegistroPeso(peso, data));
                std::cout << "Peso registrado com sucesso!\n";
            } catch (const std::exception& e) {
                std::cout << e.what() << "\n";
            }
        } else if (opcao == 2) {
            int id = lerInteiro("ID do bovino: ");
            Bovino* bovino = this->gerenciador.buscar(id);
            if (bovino == nullptr) {
                std::cout << "Bovino com ID " << id << " nao encontrado.\n";
                continue;
            }
            std::string causa = lerTexto("Causa da morte: ");
            std::string data = lerTexto("Data (DD/MM/AAAA): ");
            try {
                bovino->registrarMorte(RegistroMorte(causa, data));
                std::cout << "Morte registrada. O animal saiu do rebanho ativo.\n";
            } catch (const std::exception& e) {
                std::cout << e.what() << "\n";
            }
        } else {
            std::cout << "Opcao invalida.\n";
        }
    }
}

void Sistema::listarBovinos() {
    std::vector<Bovino> lista = this->gerenciador.listar();
    std::cout << "\n--- Rebanho (" << lista.size() << " animais) ---\n";
    if (lista.empty()) {
        std::cout << "Nenhum bovino cadastrado.\n";
        return;
    }
    for (const Bovino& b : lista) {
        std::cout << "ID: " << b.getId()
                  << " | Nome: " << b.getNome()
                  << " | Raca: " << b.getRaca()
                  << " | Idade: " << b.getIdade()
                  << " | Status: " << (b.isVivo() ? "Vivo" : "Morto")
                  << "\n";
    }
}
