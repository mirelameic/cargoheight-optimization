#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_VERTICES 100
#define INFINITY 999999

typedef struct {
    int vertices;
    float** adjMatrix;
} Graph;

void findWeight(Graph* graph, int src, int dest, float* maxPath);
void findWeightDFS(Graph* graph, int currentVertex, int dest, bool* visited, float* minWeight, float* maxPath);
Graph* createGraph(int vertices);
void addEdge(Graph* graph, int src, int dest, float weight);
void printGraph(Graph* graph);
bool isConnected(Graph* graph, int src, int dest);
float getWeight(Graph* graph, int src, int dest);