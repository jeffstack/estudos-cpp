# 📚 Pilhas de Números Pares e Ímpares

Trabalho da disciplina de **Estrutura de Dados**.

## 📋 Descrição

Programa em C++ que lê 30 números inteiros em ordem crescente e os distribui em pilhas separadas conforme a paridade (par ou ímpar). Ao final, os valores são desempilhados e exibidos em ordem decrescente.

A solução foi implementada de duas formas:
- **Lista encadeada** — alocação dinâmica de memória com ponteiros
- **Vetor (array)** — alocação estática com controle de índice

## ⚙️ Como compilar e executar

```bash
g++ -o pilhas main.cpp
./pilhas
```

## 🔄 Funcionamento

1. O programa solicita 30 números inteiros
2. Cada número precisa ser maior que o anterior (ordem crescente)
3. Números pares vão para a pilha de pares; ímpares, para a de ímpares
4. Ao final, ambas as pilhas são desempilhadas — exibindo os valores de forma decrescente
5. O processo é repetido para as duas implementações (lista e vetor)

## 🖥️ Exemplo de saída

```
Digite 30 numeros inteiros em ordem CRESCENTE.
Cada numero deve ser MAIOR que o anterior.
----------------------------------------
Numero [1/30]: 1
  -> Impar: empilhado!
Numero [2/30]: 2
  -> Par: empilhado!
...

Resultado com Lista Encadeada:

Numeros impares (decrescente):
29 27 25 ...

Numeros pares (decrescente):
30 28 26 ...
```

## 👥 Autores

- Jefferson Nascimento dos Santos
- João Pedro Badaro
