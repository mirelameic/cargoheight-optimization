# Cargo Haulage Height Optimization (using Graph Modeling)

    Projeto da disciplina Algoritmos e Estruturas de Dados 2 (EACH-USP)

## Objetivo
Desenvolver programa em linguagem C que solucione o problema da escolha da altura da carreta baú para uso na movimentação de carga por uma empresa de logística utilizando modelagem por grafos.

## Definição
A ocorrência de entalamento de veículos de transporte de carga na passagem de túneis, pontes, viadutos, praças de pedágios etc. é um problema recorrente no Brasil devido ao legado das obras de engenharia, e que causa prejuízo à economia e compromete a segurança da população.
Uma empresa de logística de carga leve que opera em todo o território nacional definiu cinco alturas padrões de 2.5, 3.0, 3.5, 4.0 e 4.5 metros, para as carretas baú de sua frota. Estas carretas são utilizadas para movimentação de carga entre as centenas de centros de distribuição espalhados pelo Brasil. O software de logística da empresa tem registrado o limite máximo de altura em metros da menor passagem existente nas rotas entre os centros de distribuição da empresa.
No caso de não existir uma passagem limitante de altura, a empresa cadastrou a altura do gabarito vertical mínimo para vias expressas estabelecido pelo DNIT que é 5.5 metros. A área de TI desta empresa quer implementar uma nova função no sistema na qual serão informados dois centros de distribuição da empresa e o sistema responda qual é a maior carreta baú que possa ser utilizada sem causar atolamento mas também transportando o maior volume de carga possível entre os centros de distribuição.

## Input/Output
O arquivo de entrada contém várias linhas. Na primeira linha são informados o número de centros de distribuição da empresa, o número de rotas entre estes centros de distribuição e a quantidade de consultas desejadas.

## Especificações
- Uso de grafos não direcionados;
- Implementações por matriz e por lista de adjacências. A aplicação é a mesma (única), apenas altera-se o #include e com diferentes alvos no Makefile;

#
## Estrutura
- `include`
  - `graph_listadj.h`:
    Declara a estrutura Node, que representa um nó em uma lista de adjacências.
    Declara a estrutura Graph, que representa um grafo usando listas de adjacências.
    Declara as funções relacionadas à manipulação do grafo, como createGraph, createNode, addEdge, printGraph, isConnected e getWeight.
  - `graph_matrixadj.h`:
    Declara a estrutura Graph, que representa um grafo usando uma matriz de adjacências.
    Declara as funções relacionadas à manipulação do grafo, como createGraph, addEdge, printGraph, isConnected e getWeight.
  - `graph_func.h`:
    Declara as funções relacionadas à lógica de negócio do programa (findWeightDFS e findWeight).

- `src`
  - `func_listadj.c`:
    Implementa as funções declaradas em graph_listadj.h para manipulação de um grafo representado por listas de adjacências.
  - `func_matrixadj.c`:
    Implementa as funções declaradas em graph_matrixadj.h para manipulação de um grafo representado por uma matriz de adjacências.
  - `graph_func.c`:
    Implementa as funções relacionadas à lógica de negócio do programa.
    Implementa a função findWeightDFS, que realiza uma busca em profundidade para encontrar o caminho máximo em um grafo.
    Implementa a função findWeight, que chama a função findWeightDFS e ajusta o resultado dentro de um intervalo específico.

- `run`
  - `main.c`:
    Lê o nome do arquivo de entrada como argumento da linha de comando.
    Abre o arquivo de entrada e verifica se foi aberto com sucesso.
    Lê o número de vértices, arestas e consultas do arquivo de entrada.
    Imprime o número de vértices, arestas e consultas lidos.
    Cria um grafo usando a função createGraph.
    Adiciona as arestas ao grafo usando a função addEdge.
    Imprime o grafo usando a função printGraph.
    Abre um arquivo de saída.
    Para cada consulta, lê os vértices de origem e destino e chama a função findWeight para encontrar o caminho máximo.
    Imprime a resposta da consulta.
    Escreve a resposta no arquivo de saída.
    Fecha os arquivos de entrada e saída.
  - `input.txt`:
    Arquivo de entrada.
  - `output.txt`:
    Arquivo de saída.

#
## Compilar (depende do include do arquivo include/graph_func.h)
~~~
$ gcc -o main run/main.c src/func_listadj.c src/graph_func.c
$ gcc -o main run/main.c src/func_matrixadj.c src/graph_func.c
~~~

## Executar
~~~
$ ./main run/input.txt
~~~