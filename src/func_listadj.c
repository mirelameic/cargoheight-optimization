#include "../include/graph_listadj.h"
#include <stdio.h>
#include <stdlib.h>

Node* createNode(int vertex, float weight) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
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

void addEdge(Graph* graph, int src, int dest, float weight) {
    Node* newNode = createNode(dest, weight);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src, weight);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void dijkstra(Graph* graph, int startVertex, int endVertex, float* minPath) {
    int numVertices = graph->vertices;
    float* dist = (float*)malloc(numVertices * sizeof(float));
    int* visited = (int*)malloc(numVertices * sizeof(int));

    for (int i = 0; i < numVertices; i++) {
        dist[i] = INFINITY;
        visited[i] = 0;
    }
    dist[startVertex] = 0;

    for (int count = 0; count < numVertices - 1; count++) {
        int u = -1;

        for (int v = 0; v < numVertices; v++) {
            if (!visited[v] && (u == -1 || dist[v] < dist[u]))
                u = v;
        }

        visited[u] = 1;

        Node* neighbor = graph->adjLists[u];
        while (neighbor != NULL) {
            int v = neighbor->vertex;
            if (!visited[v] && dist[u] + neighbor->weight < dist[v])
                dist[v] = dist[u] + neighbor->weight;
            neighbor = neighbor->next;
        }
    }

    *minPath = dist[endVertex];

    free(dist);
    free(visited);
}