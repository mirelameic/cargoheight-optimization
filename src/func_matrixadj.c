#include "../include/graph_matrixadj.h"
#include <stdlib.h>
#include <stdio.h>

void findWeight(Graph* graph, int src, int dest, float* maxPath) {
    bool* visited = (bool*)malloc(graph->vertices * sizeof(bool));
    float* minWeight = (float*)malloc(graph->vertices * sizeof(float));

    for (int i = 0; i < graph->vertices; i++) {
        visited[i] = false;
        minWeight[i] = INFINITY;
    }

    findWeightDFS(graph, src, dest, visited, minWeight, maxPath);

    float lowerLimit = 2.5;
    float upperLimit = 4.5;

    if (*maxPath < lowerLimit){
        *maxPath = lowerLimit;
    }else if (*maxPath > upperLimit){
        *maxPath = upperLimit;
    }else{
        float interval = 0.5;
        *maxPath = (int)((*maxPath - lowerLimit) / interval) * interval + lowerLimit;
    }

    free(visited);
    free(minWeight);
}

void findWeightDFS(Graph* graph, int currentVertex, int dest, bool* visited, float* minWeight, float* maxPath) {
    visited[currentVertex] = true;

    if (currentVertex == dest) {
        float currentMin = INFINITY;
        for (int i = 0; i < graph->vertices; i++) {
            if (visited[i] && minWeight[i] < currentMin) {
                currentMin = minWeight[i];
            }
        }
        if (currentMin > *maxPath) {
            *maxPath = currentMin;
        }
    } else {
        for (int i = 0; i < graph->vertices; i++) {
            if (!visited[i] && graph->adjMatrix[currentVertex][i] != INFINITY) {
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