# 📚 Sistema de Atendimento com Filas em C++

Este projeto implementa um sistema básico de atendimento ao cliente utilizando estruturas de dados de fila em C++. O objetivo é simular a geração e o atendimento de senhas, demonstrando duas abordagens diferentes para a implementação de filas: uma usando **vetores (arrays)** e outra usando **ponteiros (listas encadeadas)**.

## ✨ Funcionalidades

O sistema oferece as seguintes opções ao usuário:

*   **0. Sair:** Encerra o programa. A saída só é permitida se não houver senhas aguardando atendimento.
*   **1. Gerar Senha:** Adiciona uma nova senha à fila de espera.
*   **2. Realizar Atendimento:** Remove a primeira senha da fila de espera e a move para a fila de senhas atendidas.

Em cada interação, o sistema informa a quantidade de senhas que ainda estão aguardando atendimento. Ao finalizar, exibe o total de senhas atendidas.

## 📁 Estrutura do Projeto

O projeto é composto por dois arquivos principais, cada um contendo uma implementação da lógica de filas:

*   `atendimentoVetor.cpp`: Implementação da fila utilizando um **vetor** circular.
*   `atendimentoPonteiro.cpp`: Implementação da fila utilizando **ponteiros** (lista encadeada).

## 🚀 Como Compilar e Executar

Para compilar e executar os programas, siga os passos abaixo:

1.  **Clone o repositório:**
    ```bash
    git clone https://github.com/mmarques-ssz/ADS-EDD1-20260525.git
    cd ADS-EDD1-20260525
    ```

2.  **Compile o programa desejado (exemplo com `atendimentoVetor.cpp`):**
    ```bash
    g++ atendimentoVetor.cpp -o atendimentoVetor
    ```
    Para a versão com ponteiros, substitua `atendimentoVetor.cpp` por `atendimentoPonteiro.cpp` e `atendimentoVetor` por `atendimentoPonteiro`.

3.  **Execute o programa:**
    ```bash
    ./atendimentoVetor
    ```
    Ou `./atendimentoPonteiro` para a versão com ponteiros.

## 💻 Exemplo de Interação

```
--- SISTEMA DE ATENDIMENTO (VETOR) ---
Senhas aguardando: 0
0. Sair
1. Gerar senha
2. Realizar atendimento
Escolha uma opcao: 1

Senha 1 gerada com sucesso!
--- SISTEMA DE ATENDIMENTO (VETOR) ---
Senhas aguardando: 1
0. Sair
1. Gerar senha
2. Realizar atendimento
Escolha uma opcao: 1

Senha 2 gerada com sucesso!
--- SISTEMA DE ATENDIMENTO (VETOR) ---
Senhas aguardando: 2
0. Sair
1. Gerar senha
2. Realizar atendimento
Escolha uma opcao: 2

Atendendo a senha: 1
--- SISTEMA DE ATENDIMENTO (VETOR) ---
Senhas aguardando: 1
0. Sair
1. Gerar senha
2. Realizar atendimento
Escolha uma opcao: 0

Nao e possivel sair! Ainda ha senhas aguardando atendimento.
--- SISTEMA DE ATENDIMENTO (VETOR) ---
Senhas aguardando: 1
0. Sair
1. Gerar senha
2. Realizar atendimento
Escolha uma opcao: 2

Atendendo a senha: 2
--- SISTEMA DE ATENDIMENTO (VETOR) ---
Senhas aguardando: 0
0. Sair
1. Gerar senha
2. Realizar atendimento
Escolha uma opcao: 0

Encerrando sistema...
Total de senhas atendidas: 2
```

## 👨‍💻 Autor

*   **[Seu Nome/Usuário do GitHub]** - Estudante de Estruturas de Dados
