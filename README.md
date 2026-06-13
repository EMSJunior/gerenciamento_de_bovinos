# Sistema de Gerenciamento de Bovinos

## Descrição do Projeto
Sistema de gerenciamento de bovinos desenvolvido em C++, com controle de acesso
por tipo de usuário. Permite o cadastro e o acompanhamento das informações do
rebanho, incluindo vacinação, peso, mortes e relatórios.

O sistema possui três tipos de usuários:
- **Gerente**: cadastra bovinos e visualiza relatórios gerais (saúde e operacionais)
- **Veterinário**: registra vacinas e consulta o histórico de vacinação
- **Peão**: registra peso e mortes

---

## Como compilar e executar

> Requer `g++` (C++17) e `make`. No Windows, use o `make` do MinGW/MSYS2
> (que pode se chamar `mingw32-make`) a partir do Git Bash ou MSYS2.

### Compilar
```
make
```

### Executar
```
make run
```

### Limpar artefatos de build
```
make clean
```

O executável é gerado em `build/` (`build/gerenciamento` no Linux/Mac,
`build/gerenciamento.exe` no Windows).

---

## Link do vídeo
Vídeo de demonstração (≤ 5 min) com compilação, execução e operação do sistema:

**🎬 [(https://drive.google.com/file/d/1-512KF9yg0TyX3kRerPlenpyeIR3621D/view?usp=sharing)]**

---

## Arquitetura / Organização

### Pastas
```
include/   -> Arquivos de cabeçalho (.h) — contratos das classes
src/       -> Implementação (.cpp)
build/     -> Executável e objetos gerados (não versionado)
data/      -> Arquivos de dados (reservado para persistência futura)
docs/      -> Documentação (Doxygen) e notas de módulos
tests/     -> Testes (opcional)
```

### Módulos
- **Núcleo / Integração**: `Sistema` (fluxo principal e menus) e
  `GerenciadorBovinos` (coleção do rebanho, cadastro e busca por ID).
- **Autenticação**: `Autenticador` + hierarquia `Usuario` → `Gerente`,
  `Veterinario`, `Piao` (polimorfismo para o controle de acesso).
- **Domínio do animal**: `Bovino`, que agrega `Vacinacao`, `RegistroPeso` e
  `RegistroMorte`.
- **Relatórios**: `RelatorioSaude` (vacinação) e `RelatorioOperacional`
  (peso médio e mortalidade).

O `Sistema` orquestra os módulos: autentica via `Autenticador`, opera o rebanho
via `GerenciadorBovinos` e gera relatórios a partir dos dados dos `Bovino`s.

---

## Funcionalidades

### Implementadas
- Login com múltiplos usuários e menu específico por perfil
- Cadastro de bovinos com geração automática de ID (evita duplicidade)
- Registro de vacinação e consulta de histórico
- Registro de peso (aceita valores decimais)
- Registro de morte (atualiza o status do animal)
- Relatório geral de saúde e histórico de saúde por animal
- Relatório operacional: peso médio dos vivos e total de mortes

### Fora do escopo
- Interface gráfica
- Banco de dados real / persistência em arquivo
- Sistema web

---

## Instruções de Uso

1. Execute o programa (`make run`)
2. Faça login com usuário e senha
3. Escolha as opções do menu conforme o seu perfil
4. Para sair: faça logout (opção `0`) e deixe o usuário **em branco** na tela de login

### Usuários cadastrados (para teste)
| Usuário | Senha | Perfil |
|---------|-------|--------|
| `ger1`  | `123` | Gerente |
| `vet1`  | `123` | Veterinário |
| `peao1` | `123` | Peão |

### Exemplo de fluxo (entrada → saída)

Cadastro de um bovino pelo Gerente:
```
--- LOGIN ---
Usuario: ger1
Senha: 123
Bem-vindo, ger1 [Gerente]

========== MENU GERENTE ==========
1 - Cadastrar bovino
...
Opcao: 1
Nome/identificacao do bovino: Mimosa
Raca: Nelore
Idade (anos): 3
Bovino cadastrado com sucesso! ID gerado: 1
```

Registro de vacina pelo Veterinário e relatório de saúde:
```
Opcao: 1
ID do bovino: 1
Nome da vacina: Aftosa
Data de aplicacao (DD/MM/AAAA): 01/01/2025
Lote: L123
Vacinacao registrada com sucesso!

--- Historico de Vacinacao | Bovino ID: 1 ---
[Vacina] Aftosa | Data: 01/01/2025 | Lote: L123
```

---

## Tratamento de Exceções / Programação Defensiva

O que é tratado e **onde**:

| Situação tratada | Onde (arquivo) | Como |
|------------------|----------------|------|
| Usuário ou senha inválidos | `src/Sistema.cpp` (`login`) | Repete a tela de login; não revela se o erro é no usuário ou na senha |
| Entrada não numérica nos menus | `src/Sistema.cpp` (`lerInteiro`/`lerFloat`) | Limpa o buffer e repete a pergunta |
| Campo de texto em branco | `src/Sistema.cpp` (`lerTexto`) | Repete a pergunta até receber um valor |
| ID de bovino inexistente | `src/GerenciadorBovinos.cpp` (`buscar`) + menus | `buscar` retorna `nullptr`; o menu avisa "não encontrado" |
| IDs duplicados | `src/GerenciadorBovinos.cpp` (`gerarId`/`cadastrarBovino`) | ID é gerado pelo sistema, sempre crescente |
| Vacina/peso em animal morto | `src/Bovino.cpp` (`adicionarVacina`/`adicionarPeso`) | Lança `std::runtime_error`, capturado no menu |
| Morte de animal já morto | `src/Bovino.cpp` (`registrarMorte`) | Lança `std::runtime_error`, capturado no menu |
| Data de vacina em formato inválido | `src/Vacinacao.cpp` (construtor/`validarData`) | Lança `std::invalid_argument`, capturado no menu |

As exceções lançadas pelas classes de domínio são capturadas com `try/catch`
nos menus do `Sistema`, exibindo a mensagem ao usuário sem encerrar o programa.

---

## Documentação (Doxygen)

### Gerar
```
doxygen Doxyfile
```

### Acessar
Abrir o arquivo gerado:
```
docs/html/index.html
```

A configuração (`Doxyfile`) já aponta para `include/`, `src/` e usa este
`README.md` como página inicial.

---

## Equipe e Contribuições

Contribuições relacionadas aos commits do repositório:

| Dev | Nome | Responsabilidade | Evidência (commits/PRs) |
|-----|------|------------------|-------------------------|
| **Dev 1** | Edson Mendes de Souza Júnior | Líder / Integração: organização das classes, fluxo principal e menus | *"Organização inicial... arquivos .h"*; *"implementa classes e lógica do sistema"* |
| **Dev 2** | Thiago Tavares Santos Vasconcelos | Login: classes de usuário, autenticação e controle de acesso | *"módulo de login, classes de usuário e autenticação"*; **PR #1** (`thiago-login`) |
| **Dev 3** | João Pedro Soares Ferraz | Vacinação + Relatórios de saúde | *"implementa a lógica de Vacinacao"*, *"RelatorioSaude"*, *"métodos de saude e vacinacao a bovino.cpp"* |
| **Dev 4** | Luis Antonio Ferreira Manhães | Peso + Morte + Relatórios operacionais | *"Implementação dos Registros e Relatório"*; **PR #3** (`feature-peso-mortalidade-luis`) |

---

## Ciclo de Desenvolvimento (Sprints)

Linha do tempo baseada no histórico do repositório (06/05/2026 → 13/06/2026).

### Sprint 1 — Estrutura e Planejamento (06/05 – 07/05/2026)
- **Objetivo**: configurar ambiente, repositório e modelagem inicial.
- **Entregas**: estrutura de diretórios, User Stories, Cartões CRC e os
  contratos `.h` para padronização do projeto.
- **Evidências**: commits de estrutura inicial e documentação; commit de teste
  de cada integrante validando o fluxo no GitHub.

### Sprint 2 — Login e Acesso (07/05 – 22/05/2026)
- **Objetivo**: implementar autenticação e controle de acesso.
- **Entregas**: `Autenticador`, hierarquia `Usuario`/`Gerente`/`Veterinario`/`Piao`.
- **Evidências**: **PR #1** (`thiago-login`).

### Sprint 3 — Funcionalidades de Domínio (22/05 – 10/06/2026)
- **Objetivo**: peso, morte, vacinação e relatórios.
- **Entregas**: `RegistroPeso`, `RegistroMorte`, `RelatorioOperacional`
  (Luis); `Vacinacao`, `RelatorioSaude` e métodos de saúde no `Bovino` (João).
- **Evidências**: **PR #3** (`feature-peso-mortalidade-luis`) e commits de
  vacinação/relatório de saúde.

### Sprint Final — Integração e Refinamento (11/06 – 13/06/2026)
- **Objetivo**: integrar tudo, completar implementação e documentar.
- **Entregas**: `Sistema`, `GerenciadorBovinos` e `main` (fluxo e menus);
  `Makefile`; `Doxyfile`; comentários Doxygen; programação defensiva nos menus.

### Planejado × Realizado
- **Modelagem × código**: os Cartões CRC previam uma classe `RegistroVacina`
  e persistência em `data/`. Na implementação, a classe ficou como `Vacinacao`
  e a persistência foi mantida **fora do escopo** desta entrega.
- **Coleção do rebanho**: o CRC previa "vetor ou lista"; optou-se por um
  `std::map<int, Bovino>` para garantir busca direta por ID e impedir
  duplicidade, mantendo `listar()` para os relatórios que usam vetor.
- **Impedimento**: divergências entre os contratos `.h` e as implementações dos
  módulos foram reconciliadas na sprint de integração.

### Aprendizados
- Definir contratos (`.h`) cedo ajuda o trabalho paralelo, mas exige uma fase
  de integração para alinhar nomes/assinaturas entre os módulos.
- Uso de `git` com branches e Pull Requests para revisão (PRs #1 e #3).
- Programação defensiva concentrada na fronteira de entrada (menus) e nas
  invariantes das classes de domínio (lançando exceções).

---

## Considerações Finais
O sistema entrega o ciclo completo de gestão do rebanho proposto nas User
Stories, com controle de acesso por perfil, tratamento de erros e documentação
automatizada via Doxygen.
