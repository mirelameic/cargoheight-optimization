#define INFINITY 999999

typedef struct Node {
    int vertex;
    float weight;
    struct Node* next;
} Node;

typedef struct {
    int vertices;
    Node** adjLists;
} Graph;