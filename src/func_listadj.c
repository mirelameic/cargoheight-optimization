#include "../include/graph_listadj.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

void findWeight(Graph* graph, int src, int dest, float* maxPath);
void findWeightDFS(Graph* graph, int currentVertex, int dest, bool* visited, float* minWeight, float* maxPath);
Graph* createGraph(int vertices);
Node* createNode(int vertex, float weight);
void addEdge(Graph* graph, int src, int dest, float weight);
void printGraph(Graph* graph);

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

void findWeight(Graph* graph, int src, int dest, float* maxPath) {
    bool* visited = (bool*)malloc(graph->vertices * sizeof(bool));
    float* minWeight = (float*)malloc(graph->vertices * sizeof(float));

    // Inicialização dos arrays
    for (int i = 0; i < graph->vertices; i++) {
        visited[i] = false;
        minWeight[i] = INT_MAX;
    }

    findWeightDFS(graph, src, dest, visited, minWeight, maxPath);

    free(visited);
    free(minWeight);
}

void findWeightDFS(Graph* graph, int currentVertex, int dest, bool* visited, float* minWeight, float* maxPath) {
    visited[currentVertex] = true;

    if (currentVertex == dest) {
        // Atualiza o máximo caminho mínimo encontrado
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

            if (!visited[adjVertex] && weight < minWeight[adjVertex]) {
                minWeight[adjVertex] = weight;
                findWeightDFS(graph, adjVertex, dest, visited, minWeight, maxPath);
                minWeight[adjVertex] = INT_MAX;  // Restaura o peso máximo
            }

            temp = temp->next;
        }
    }

    visited[currentVertex] = false;
}