/*Given an undirected graph with V vertices and E edges, represented as a 2D vector edges[][], where each entry edges[i] = 
[u, v] denotes an edge between vertices u and v, determine whether the graph contains a cycle or not.
Note: The graph can have multiple component*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX];   // Adjacency matrix
int visited[MAX];

// DFS function to detect cycle
int dfs(int node, int parent, int V) {
    visited[node] = 1;

    for (int i = 0; i < V; i++) {
        if (graph[node][i]) {  // If edge exists
            if (!visited[i]) {
                if (dfs(i, node, V))
                    return 1;
            }
            else if (i != parent) {
                return 1;  // Cycle found
            }
        }
    }
    return 0;
}

// Function to check cycle in graph
int hasCycle(int V) {
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, V))
                return 1;
        }
    }
    return 0;
}

int main() {
    int V, E;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    // Initialize graph and visited array
    for (int i = 0; i < V; i++) {
        visited[i] = 0;
        for (int j = 0; j < V; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter edges (u v):\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;  // Undirected graph
    }

    if (hasCycle(V))
        printf("Cycle detected\n");
    else
        printf("No cycle\n");

    return 0;
}
