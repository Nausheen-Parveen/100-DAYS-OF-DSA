/*Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges. 
The graph is represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes a direct edge from vertex u to v. 
Find the number of strongly connected components in the graph.*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Adjacency list node
struct Node {
    int vertex;
    struct Node* next;
};

// Graph structure
struct Graph {
    int V;
    struct Node* adj[MAX];
};

// Stack for DFS
int stack[MAX], top = -1;
int visited[MAX];

// Create a new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Create graph
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    for (int i = 0; i < V; i++)
        graph->adj[i] = NULL;
    return graph;
}

// Add edge u -> v
void addEdge(struct Graph* graph, int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = graph->adj[u];
    graph->adj[u] = newNode;
}

// DFS to fill stack (order of finishing time)
void dfsFill(struct Graph* graph, int v) {
    visited[v] = 1;
    struct Node* temp = graph->adj[v];

    while (temp) {
        if (!visited[temp->vertex])
            dfsFill(graph, temp->vertex);
        temp = temp->next;
    }

    stack[++top] = v; // push to stack
}

// DFS on transposed graph
void dfs(struct Graph* graph, int v) {
    visited[v] = 1;
    struct Node* temp = graph->adj[v];

    while (temp) {
        if (!visited[temp->vertex])
            dfs(graph, temp->vertex);
        temp = temp->next;
    }
}

// Transpose graph
struct Graph* transposeGraph(struct Graph* graph) {
    struct Graph* transpose = createGraph(graph->V);

    for (int i = 0; i < graph->V; i++) {
        struct Node* temp = graph->adj[i];
        while (temp) {
            addEdge(transpose, temp->vertex, i);
            temp = temp->next;
        }
    }
    return transpose;
}

// Function to count SCCs
int countSCC(struct Graph* graph) {
    // Step 1: Fill stack with finishing order
    for (int i = 0; i < graph->V; i++)
        visited[i] = 0;

    for (int i = 0; i < graph->V; i++)
        if (!visited[i])
            dfsFill(graph, i);

    // Step 2: Transpose graph
    struct Graph* transpose = transposeGraph(graph);

    // Step 3: DFS using stack order
    for (int i = 0; i < graph->V; i++)
        visited[i] = 0;

    int sccCount = 0;

    while (top >= 0) {
        int v = stack[top--];

        if (!visited[v]) {
            dfs(transpose, v);
            sccCount++;
        }
    }

    return sccCount;
}

// Driver code
int main() {
    int V = 5;
    struct Graph* graph = createGraph(V);

    addEdge(graph, 0, 2);
    addEdge(graph, 2, 1);
    addEdge(graph, 1, 0);
    addEdge(graph, 0, 3);
    addEdge(graph, 3, 4);

    int result = countSCC(graph);
    printf("Number of Strongly Connected Components: %d\n", result);

    return 0;
}
