# 👔 Gerenciador de Funcionários

Programa em C++ que gerencia uma lista de funcionários através de um menu interativo. A lista é implementada com **lista encadeada** e permite incluir, excluir, pesquisar e listar funcionários, exibindo ao final o total dos salários.

## ⚙️ Como compilar e executar

```bash
g++ -o funcionarios main.cpp
./funcionarios
```

## 🔄 Funcionamento

O programa oferece um menu com as seguintes opções:

- **0. Sair** — encerra o programa e libera a memória
- **1. Incluir** — cadastra um novo funcionário (prontuário, nome e salário)
- **2. Excluir** — remove um funcionário pelo prontuário
- **3. Pesquisar** — busca um funcionário pelo prontuário e exibe seus dados
- **4. Listar** — exibe todos os funcionários cadastrados e o total dos salários

> Não é permitido cadastrar dois funcionários com o mesmo prontuário.

## 🖥️ Exemplo de saída

```
Menu:
0. Sair
1. Incluir
2. Excluir
3. Pesquisar
4. Listar
Escolha uma opção: 4

----------- Listagem de Funcionários -----------
Prontuário: 2 | Nome: Maria Silva | Salário: R$ 4500.00
Prontuário: 1 | Nome: João Santos | Salário: R$ 3200.00
------------------------------------------------
Total dos Salários: R$ 7700.00
------------------------------------------------