#include "../include/graph_matrixadj.h"

Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertices = vertices;
    graph->adjMatrix = (float**)malloc(vertices * sizeof(float*));
    for (int i = 0; i < vertices; i++) {
        graph->adjMatrix[i] = (float*)malloc(vertices * sizeof(float));
        for (int j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = INFINITY;
        }
    }

    return graph;
}

void addEdge(Graph* graph, int src, int dest, float weight) {
    graph->adjMatrix[src][dest] = weight;
    graph->adjMatrix[dest][src] = weight;
}

void printGraph(Graph* graph) {
    int i, j;
    for (i = 0; i < graph->vertices; i++) {
        printf("V%d: ", i);
        for (j = 0; j < graph->vertices; j++) {
            float weight = graph->adjMatrix[i][j];
            if (weight != INFINITY) {
                printf("-> (%d, peso: %.2f) ", j, weight);
            }
        }
        printf("\n");
    }
}

bool isConnected(Graph* graph, int src, int dest){
    return (graph->adjMatrix[src][dest] != INFINITY);
}

float getWeight(Graph* graph, int src, int dest){
    return graph->adjMatrix[src][dest];
}