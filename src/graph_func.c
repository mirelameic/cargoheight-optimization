#include "../include/graph_func.h"

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
            if (!visited[i] && isConnected(graph, currentVertex, i)) {
                minWeight[i] = getWeight(graph, currentVertex, i);
                findWeightDFS(graph, i, dest, visited, minWeight, maxPath);
                minWeight[i] = INFINITY;
            }
        }
    }

    visited[currentVertex] = false;
}

void findWeight(Graph* graph, int src, int dest, float* maxPath) {
    bool* visited = (bool*)malloc(graph->vertices * sizeof(bool));
    float* minWeight = (float*)malloc(graph->vertices * sizeof(float));

    for (int i = 0; i < graph->vertices; i++) {
        visited[i] = false;
        minWeight[i] = INFINITY;
    }

    findWeightDFS(graph, src, dest, visited, minWeight, maxPath);

    // not working properly:
    
    // float lowerLimit = 2.5;
    // float upperLimit = 4.5;

    // if (*maxPath < lowerLimit) {
    //     *maxPath = lowerLimit;
    // } else if (*maxPath > upperLimit) {
    //     *maxPath = upperLimit;
    // } else {
    //     float interval = 0.5;
    //     *maxPath = (int)((*maxPath - lowerLimit) / interval) * interval + lowerLimit;
    // }


    if (*maxPath <= 2.5) {
        *maxPath = 2.5;
    } else if (*maxPath <= 3.4) {
        *maxPath = 3.0;
    } else if (*maxPath <= 3.9) {
        *maxPath = 3.5;
    } else if (*maxPath <= 4.5) {
        *maxPath = 4.0;
    } else if (*maxPath <= 4.9) {
        *maxPath = 4.5;
    } else if (*maxPath >= 5.0){
        *maxPath = 5.0;
    }  

    free(visited);
    free(minWeight);
}