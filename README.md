# Projeto: Grafo de Cidades do Piauí 

Este projeto implementa um grafo em linguagem C representando 10 cidades do estado do Piauí, utilizando estrutura de lista de adjacência. A partir do grafo, são realizados algoritmos de percurso para:

- Listar **todos os caminhos possíveis** entre duas cidades
- Determinar o **caminho mais curto** usando **BFS**
- Determinar o **caminho mais longo** usando **DFS com backtracking**


##  Cidades Representadas

As cidades são indexadas de 0 a 9, associadas a:

| Índice | Cidade         |
|--------|----------------|
| 0      | Corrente       |
| 1      | Gilbués        |
| 2      | Bom Jesus      |
| 3      | Floriano       |
| 4      | Oeiras         |
| 5      | Teresina       |
| 6      | Campo Maior    |
| 7      | Piripiri       |
| 8      | Luís Correia   |
| 9      | Parnaíba       |


##  Funcionalidades

-  Representação de grafo com lista de adjacência
-  Inserção de arestas direcionadas entre cidades
-  Listagem de **todos os caminhos** possíveis entre Corrente e Parnaíba
-  Cálculo do **caminho mais curto** (em número de cidades) via **Busca em Largura (BFS)**
-  Determinação do **caminho mais longo possível** entre duas cidades com **DFS**

