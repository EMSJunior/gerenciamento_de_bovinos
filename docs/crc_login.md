# Cartões CRC — Módulo de Login

Responsável: Thiago Tavares Santos Vasconcelos

---

## Classe: Usuario

### Responsabilidades

- Armazenar o nome de usuário.
- Armazenar a senha do usuário.
- Validar a senha informada.
- Servir como classe base para os diferentes tipos de usuários.
- Definir uma interface comum por meio do método `getTipo()`.

### Colaboradores

- Autenticador
- Gerente
- Veterinario
- Piao

---

## Classe: Gerente

### Responsabilidades

- Representar um usuário com perfil de gerente.
- Informar que o tipo do usuário é `Gerente`.
- Permitir acesso às funcionalidades administrativas do sistema.
- Permitir acesso aos relatórios gerais.

### Colaboradores

- Usuario
- Autenticador
- Sistema

---

## Classe: Veterinario

### Responsabilidades

- Representar um usuário com perfil de veterinário.
- Informar que o tipo do usuário é `Veterinario`.
- Permitir acesso às funcionalidades relacionadas à saúde dos bovinos.
- Permitir registro e acompanhamento de vacinações.

### Colaboradores

- Usuario
- Autenticador
- Vacinacao
- Sistema

---

## Classe: Piao

### Responsabilidades

- Representar um usuário com perfil operacional.
- Informar que o tipo do usuário é `Piao`.
- Permitir acesso a registros operacionais, como peso e morte de bovinos.
- Restringir acesso a funcionalidades administrativas.

### Colaboradores

- Usuario
- Autenticador
- RegistroPeso
- RegistroMorte
- Sistema

---

## Classe: Autenticador

### Responsabilidades

- Armazenar a lista de usuários cadastrados.
- Adicionar usuários ao sistema.
- Validar login e senha.
- Retornar o usuário autenticado.
- Negar acesso quando as credenciais forem inválidas.

### Colaboradores

- Usuario
- Gerente
- Veterinario
- Piao
- Sistema
