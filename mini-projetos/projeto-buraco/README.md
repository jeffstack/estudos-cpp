# 🃏 Simulador de Distribuição de Cartas (Buraco)

Mini-projeto com foco na prática de alocação dinâmica de memória, manipulação de matrizes com ponteiros e lógica de randomização para simulação de distribuição de cartas.

---

## 📌 Sobre

O programa simula a criação de dois baralhos completos (104 cartas no total) e realiza a distribuição aleatória de cartas para 4 jogadores, garantindo que não haja repetição. Cada jogador recebe 11 cartas, e ao final são exibidas todas as mãos.


As cartas seguem o formato: **N-99-B**, onde:
- **N** → Naipe (1-Copas / 2-Paus / 3-Ouro / 4-Espada)
- **99** → Valor da carta (01-Ás até 13-Rei)
- **B** → Baralho (1 ou 2)

Essa representação permite armazenar todas as informações da carta em um único número inteiro.

---

## 🛠️ Funcionalidades

- Criação de dois baralhos completos em memória
- Representação das cartas em formato estruturado (naipe, valor e baralho)
- Distribuição aleatória de cartas para os jogadores
- Garantia de não repetição de cartas
- Exibição das mãos de cada jogador no terminal

---

## 💡 Conceitos praticados

- Matrizes bidimensionais
- Ponteiro para ponteiro (`int**`)
- Alocação dinâmica de memória (`new` e `delete`)
- Geração de números aleatórios (`rand()` e `srand(time(NULL))`)
- Lógica de controle de duplicidade de dados

---

## ▶️ Como executar

1. Compile o arquivo `.cpp`
```bash
g++ main.cpp -o baralho