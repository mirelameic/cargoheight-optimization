#include "../src/func_listadj.c"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Uso: %s arquivo_entrada\n", argv[0]);
        return 1;
    }

    FILE* inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        printf("Não foi possível abrir o arquivo de entrada.\n");
        return 1;
    }

    int numVertices, numEdges, numQueries;
    fscanf(inputFile, "%d %d %d", &numVertices, &numEdges, &numQueries);

    Graph* graph = createGraph(numVertices);

    // Preencher o grafo com as informações das rotas e limites de altura
    for (int i = 0; i < numEdges; i++) {
        int src, dest;
        float height;
        fscanf(inputFile, "%d %d %f", &src, &dest, &height);
        addEdge(graph, src - 1, dest - 1, height);
    }

    // Realizar as consultas e determinar a maior carreta baú possível
    FILE* outputFile = fopen("run/output.txt", "w");
    for (int i = 0; i < numQueries; i++) {
        int src, dest;
        fscanf(inputFile, "%d %d", &src, &dest);
        float minPath;
        dijkstra(graph, src - 1, dest - 1, &minPath);
        fprintf(outputFile, "%.1f\n", minPath);
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}