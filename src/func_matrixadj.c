#include"../include/graph_matrixadj.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

void findWeight(Graph* graph, int src, int dest, float* maxPath);
void findWeightDFS(Graph* graph, int currentVertex, int dest, bool* visited, float* minWeight, float* maxPath);
Graph* createGraph(int vertices);
void addEdge(Graph* graph, int src, int dest, float weight);
void printGraph(Graph* graph);

void findWeight(Graph* graph, int src, int dest, float* maxPath) {
    bool* visited = (bool*)malloc(graph->vertices * sizeof(bool));
    float* minWeight = (float*)malloc(graph->vertices * sizeof(float));

    for (int i = 0; i < graph->vertices; i++) {
        visited[i] = false;
        minWeight[i] = INFINITY;
    }

    minWeight[src] = 0.0;
    *maxPath = -INFINITY;

    findWeightDFS(graph, src, dest, visited, minWeight, maxPath);

    free(visited);
    free(minWeight);
}

void findWeightDFS(Graph* graph, int currentVertex, int dest, bool* visited, float* minWeight, float* maxPath) {
    visited[currentVertex] = true;

    if (currentVertex == dest) {
        float currentMin = INFINITY;
        for (int i = 0; i < graph->vertices; i++) {
            if (visited[i] && graph->adjMatrix[currentVertex][i] < currentMin) {
                currentMin = graph->adjMatrix[currentVertex][i];
            }
        }
        if (currentMin > *maxPath) {
            *maxPath = currentMin;
        }
    } else {
        for (int i = 0; i < graph->vertices; i++) {
            if (!visited[i] && graph->adjMatrix[currentVertex][i] != INFINITY &&
                graph->adjMatrix[currentVertex][i] < minWeight[i]) {
                minWeight[i] = graph->adjMatrix[currentVertex][i];
                findWeightDFS(graph, i, dest, visited, minWeight, maxPath);
                minWeight[i] = INFINITY;
            }
        }
    }

    visited[currentVertex] = false;
}

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