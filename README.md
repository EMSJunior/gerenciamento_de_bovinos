# Sistema de Gerenciamento de Bovinos

## Descrição do Projeto
Este projeto consiste em um sistema de gerenciamento de bovinos desenvolvido em C++, com controle de acesso por tipo de usuário. O sistema permite o cadastro e acompanhamento de informações do rebanho, incluindo vacinação, peso, mortes e relatórios.

O sistema possui três tipos de usuários:
- Gerente: visualiza relatórios gerais
- Veterinário: registra vacinas
- Peão: registra peso e mortes

---

## Como compilar e executar

### Compilar:
make

### Executar:
make run

---

## Arquitetura do Projeto

include/   -> Arquivos de cabeçalho (.h)  
src/       -> Implementação (.cpp)  
data/      -> Arquivos de dados (persistência)  
build/     -> Executável gerado  
docs/      -> Documentação (Doxygen)  
tests/     -> Testes (opcional)  

Obs.: Os arquivos .h foram gerados com base na idealização do trabalho e pode sofrer alterações.

---

## Funcionalidades

### Implementadas
- Sistema de login com múltiplos usuários
- Cadastro de bovinos
- Registro de vacinação
- Registro de peso
- Registro de morte
- Geração de relatórios

### Fora do escopo
- Interface gráfica
- Banco de dados real
- Sistema web

---

## Instruções de Uso

1. Execute o programa  
2. Faça login com usuário e senha  
3. Escolha as opções do menu de acordo com o tipo de usuário  

### Exemplo de fluxo:

Login: vet1  
Senha: 123  

[Veterinário]  
1 - Registrar vacinação  

---

## Programação Defensiva

O sistema trata:
- IDs inválidos
- Bovinos inexistentes
- Erros de entrada
- Tentativas de acesso indevido

Validações são feitas principalmente nas classes:
- GerenciadorBovinos
- Autenticador
- Sistema

---

## Documentação (Doxygen)

### Gerar documentação:
doxygen Doxyfile

### Acessar:
Abrir o arquivo:
docs/html/index.html

---

## Vídeo

Link do vídeo :  
EM PRODUÇÂO

---

## Equipe

### Dev 1 — Líder / Integração
Nome: Edson Mendes de Souza Júnior
Responsabilidades:
- Organização das classes
- Integração do sistema com login
- Fluxo principal e menus

---

### Dev 2 — Sistema de Login 
Nome: Thiago Tavares Santos Vasconcelos
Responsabilidades:
- Implementação das classes de usuário
- Sistema de autenticação
- Controle de acesso

---

### Dev 3 — Vacinação + Relatórios de Saúde
Nome: João Pedro Soares Ferraz 
Responsabilidades:
- Registro de vacinas
- Histórico de vacinação
- Relatórios de saúde

---

### Dev 4 — Peso + Morte + Relatórios Operacionais - 
Nome: Luis Antonio Ferreira Manhaes
Responsabilidades:
- Registro de peso
- Registro de mortes
- Relatórios operacionais

---

## Ciclo de Desenvolvimento (Sprints)

### Sprint 1
Objetivo: Estrutura inicial + login  
Entrega: Classes base e autenticação  

### Sprint 2
Objetivo: Funcionalidades principais  
Entrega: Vacinação, peso e morte  

### Sprint 3
Objetivo: Integração e testes  
Entrega: Sistema completo funcionando  

### Sprint Final
Objetivo: Refinamento  
Entrega: Documentação + vídeo  


## Considerações Finais
