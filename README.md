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
  - `graph_matrixadj.h`:

- `src`
  - `func_listadj.c`:
  - `func_matrixadj.c`:

- `run`
  - `main.c`:
  - `txt-entrada.txt`:
  - `txt-saida.txt`:

#
## Compilar
~~~
$ gcc run/main.c -o main -lm
~~~

## Executar
~~~
./main run/txt-entrada.txt
~~~