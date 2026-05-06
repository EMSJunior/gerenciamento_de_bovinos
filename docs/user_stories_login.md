# User Stories — Módulo de Login

Responsável: Thiago Tavares Santos Vasconcelos

## US01 — Login no sistema

Como usuário cadastrado,  
quero informar meu nome de usuário e senha,  
para acessar o sistema de acordo com minha função.

### Critérios de aceitação

- O sistema deve verificar se o usuário existe.
- O sistema deve validar a senha informada.
- O sistema deve negar o acesso caso login ou senha estejam incorretos.
- O sistema deve identificar o tipo do usuário autenticado.

---

## US02 — Controle de acesso por perfil

Como usuário autenticado,  
quero acessar apenas as funcionalidades permitidas ao meu perfil,  
para evitar alterações indevidas no sistema.

### Critérios de aceitação

- O gerente deve ter acesso às funcionalidades administrativas e relatórios.
- O veterinário deve ter acesso às funcionalidades relacionadas à saúde dos animais.
- O peão deve ter acesso às funcionalidades operacionais, como registros de peso e morte.
- O sistema deve impedir o acesso a funcionalidades não permitidas ao perfil do usuário.

---

## US03 — Tipos de usuários do sistema

Como sistema,  
quero diferenciar os usuários por tipo,  
para aplicar permissões diferentes durante a execução.

### Critérios de aceitação

- O sistema deve reconhecer usuários do tipo Gerente.
- O sistema deve reconhecer usuários do tipo Veterinário.
- O sistema deve reconhecer usuários do tipo Peão.
- Cada tipo de usuário deve possuir uma identificação própria.

---

## US04 — Falha de autenticação

Como usuário,  
quero receber uma mensagem clara quando errar login ou senha,  
para entender que o acesso não foi permitido.

### Critérios de aceitação

- O sistema deve informar que as credenciais são inválidas.
- O sistema não deve encerrar de forma inesperada.
- O sistema deve permitir uma nova tentativa ou retorno ao menu inicial.