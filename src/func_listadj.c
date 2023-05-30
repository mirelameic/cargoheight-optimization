#include "../include/graph_listadj.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void findWeight(Graph* graph, int src, int dest, float* maxPath);
void findWeightDFS(Graph* graph, int currentVertex, int dest, bool* visited, float* minWeight, float* maxPath);
Graph* createGraph(int vertices);
Node* createNode(int vertex, float weight);
void addEdge(Graph* graph, int src, int dest, float weight);
void printGraph(Graph* graph);

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
        Node* temp = graph->adjLists[currentVertex];
        while (temp != NULL) {
            int adjVertex = temp->vertex;
            float weight = temp->weight;

            if (!visited[adjVertex]) {
                minWeight[adjVertex] = weight;
                findWeightDFS(graph, adjVertex, dest, visited, minWeight, maxPath);
                minWeight[adjVertex] = INFINITY;
            }

            temp = temp->next;
        }
    }

    visited[currentVertex] = false;
}

Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertices = vertices;

    graph->adjLists = (Node**)malloc(vertices * sizeof(Node*));
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }

    return graph;
}

Node* createNode(int vertex, float weight) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

void addEdge(Graph* graph, int src, int dest, float weight) {
    Node* newNode = createNode(dest, weight);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src, weight);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void printGraph(Graph* graph) {
    int i;
    for (i = 0; i < graph->vertices; i++) {
        Node* temp = graph->adjLists[i];
        printf("V%d: ", i);
        while (temp) {
            printf("-> (%d, peso: %.2f) ", temp->vertex, temp->weight);
            temp = temp->next;
        }
        printf("\n");
    }
}