#include"../include/graph_matrixadj.h"
#include <stdio.h>
#include <stdlib.h>

Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertices = vertices;

    // Alocar memória para a matriz de adjacências
    graph->adjMatrix = (float**)malloc(vertices * sizeof(float*));
    for (int i = 0; i < vertices; i++) {
        graph->adjMatrix[i] = (float*)malloc(vertices * sizeof(float));
        for (int j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = INFINITY;  // inicialmente, não há arestas entre os vértices
        }
    }

    return graph;
}

void addEdge(Graph* graph, int src, int dest, float weight) {
    graph->adjMatrix[src][dest] = weight;
    graph->adjMatrix[dest][src] = weight;  // considerando o grafo não direcionado
}

void dijkstra(Graph* graph, int startVertex, int endVertex, float* minPath) {
    int numVertices = graph->vertices;
    float* dist = (float*)malloc(numVertices * sizeof(float));
    int* visited = (int*)malloc(numVertices * sizeof(int));

    // Inicializar distâncias e visited
    for (int i = 0; i < numVertices; i++) {
        dist[i] = INFINITY;
        visited[i] = 0;
    }
    dist[startVertex] = 0;

    for (int count = 0; count < numVertices - 1; count++) {
        int u = -1;

        // Escolher o vértice de menor distância não visitado
        for (int v = 0; v < numVertices; v++) {
            if (!visited[v] && (u == -1 || dist[v] < dist[u]))
                u = v;
        }

        visited[u] = 1;

        // Atualizar distâncias dos vértices adjacentes a u
        for (int v = 0; v < numVertices; v++) {
            if (!visited[v] && graph->adjMatrix[u][v] != INFINITY && dist[u] + graph->adjMatrix[u][v] < dist[v])
                dist[v] = dist[u] + graph->adjMatrix[u][v];
        }
    }

    // Armazenar a menor altura no caminho mínimo
    *minPath = dist[endVertex];

    free(dist);
    free(visited);
}