# Projeto Final - Gestor de Despesas de República
**Programação e Desenvolvimento de Software 2 - 2/2025**
**Alunos:** Gustavo Salles, Ana Clara Nunes, Filipe Lemos
---
## 1. Apresentação do Problema
[cite_start][cite: 60]
(Aqui você vai escrever uma breve apresentação do problema. Fale sobre a dificuldade de gerenciar contas em uma república, como dividir os valores, quem pagou o quê, e como o seu software se propõe a resolver isso de forma organizada.)
## 2. Visão Geral da Solução (Estrutura do Programa)
[cite_start][cite: 60]
(Aqui você vai descrever a arquitetura do seu sistema. Explique as principais classes que você criou e o que cada uma faz. Por exemplo:)
* **Classe `Morador`:** Armazena os dados de cada pessoa e seu saldo atual.
* **Classe `Despesa` (Abstrata):** Serve como base para os diferentes tipos de despesa.
* **Classe `DespesaComum`:** Implementa a lógica de divisão igualitária.
* **Classe `DespesaIndividual`:** Implementa a lógica de gasto pessoal.
* **Classe `Republica`:** É a classe principal que gerencia a lista de moradores e o histórico de despesas.
* ... (e assim por diante)
## 3. Como Compilar e Executar
(Esta seção é bônus, mas é uma ótima prática)
Para compilar o projeto, execute:
```bash
make

# GerenciadorDispesaUniv
Projeto Final da disciplina de Progamação e Desenvolvimento de Software II
+-- /include/                 <-- Arquivos .hpp (Cabeçalhos)
|   |-- morador.hpp
|   |-- despesa.hpp
|   |-- despesa_comum.hpp
|   |-- despesa_individual.hpp
|   |-- pagamento.hpp
|   |-- republica.hpp
|
+-- /src/                     <-- Arquivos .cpp (Implementação)
|   |-- morador.cpp
|   |-- despesa.cpp
|   |-- despesa_comum.cpp
|   |-- despesa_individual.cpp
|   |-- pagamento.cpp
|   |-- republica.cpp
|   |-- main.cpp              <-- Ponto de entrada
|
+-- Makefile                  <-- Arquivo de compilação [cite: 72]
+-- README.md                 <-- 
