#include "../include/graph_listadj.h"

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

bool isConnected(Graph* graph, int src, int dest){
    Node* temp = graph->adjLists[src];
    while (temp != NULL) {
        if (temp->vertex == dest) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

float getWeight(Graph* graph, int src, int dest){
    Node* temp = graph->adjLists[src];
    while (temp != NULL) {
        if (temp->vertex == dest) {
            return temp->weight;
        }
        temp = temp->next;
    }
    return INFINITY;
}