/*Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

class Node {
    public int val;
    public List<Node> neighbors;
}*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Definition of Node
struct Node {
    int val;
    int numNeighbors;
    struct Node** neighbors;
};

// Hash map (simple array-based for mapping)
struct Node* visited[MAX];

// Function to create a new node
struct Node* createNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->numNeighbors = 0;
    node->neighbors = (struct Node**)malloc(MAX * sizeof(struct Node*));
    return node;
}

// DFS function to clone graph
struct Node* cloneGraph(struct Node* node) {
    if (node == NULL)
        return NULL;

    // If already visited, return the cloned node
    if (visited[node->val] != NULL)
        return visited[node->val];

    // Create clone
    struct Node* clone = createNode(node->val);
    visited[node->val] = clone;

    // Clone neighbors
    for (int i = 0; i < node->numNeighbors; i++) {
        clone->neighbors[clone->numNeighbors++] =
            cloneGraph(node->neighbors[i]);
    }

    return clone;
}

// Utility to add edge
void addEdge(struct Node* u, struct Node* v) {
    u->neighbors[u->numNeighbors++] = v;
}

// Driver code
int main() {
    // Initialize visited array
    for (int i = 0; i < MAX; i++)
        visited[i] = NULL;

    // Create sample graph
    struct Node* node1 = createNode(1);
    struct Node* node2 = createNode(2);
    struct Node* node3 = createNode(3);
    struct Node* node4 = createNode(4);

    addEdge(node1, node2);
    addEdge(node1, node4);

    addEdge(node2, node1);
    addEdge(node2, node3);

    addEdge(node3, node2);
    addEdge(node3, node4);

    addEdge(node4, node1);
    addEdge(node4, node3);

    // Clone graph
    struct Node* clonedGraph = cloneGraph(node1);

    printf("Cloned node value: %d\n", clonedGraph->val);

    return 0;
}
