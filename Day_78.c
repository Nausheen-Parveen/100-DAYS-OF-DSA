/*Given an undirected connected graph with V vertices and adjacency list adj. You are required to find all the vertices removing which (and edges through it) disconnects the graph into 2 or more components and return it in sorted manner.
Note: Indexing is zero-based i.e nodes numbering from (0 to V-1). There might be loops present in the graph.*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int V;
int timeCounter;

// DFS function
void dfs(int u, int visited[], int disc[], int low[], int parent[], int ap[], int adj[MAX][MAX]) {
    int children = 0;
    visited[u] = 1;

    disc[u] = low[u] = ++timeCounter;

    for (int v = 0; v < V; v++) {
        if (adj[u][v] == 0) continue; // no edge

        if (!visited[v]) {
            children++;
            parent[v] = u;

            dfs(v, visited, disc, low, parent, ap, adj);

            // Update low value
            if (low[v] < low[u])
                low[u] = low[v];

            // Case 1: root node
            if (parent[u] == -1 && children > 1)
                ap[u] = 1;

            // Case 2: non-root node
            if (parent[u] != -1 && low[v] >= disc[u])
                ap[u] = 1;
        }
        else if (v != parent[u]) {
            // Back edge
            if (disc[v] < low[u])
                low[u] = disc[v];
        }
    }
}

// Function to find articulation points
void findArticulationPoints(int adj[MAX][MAX]) {
    int visited[MAX] = {0};
    int disc[MAX];
    int low[MAX];
    int parent[MAX];
    int ap[MAX] = {0};

    for (int i = 0; i < V; i++) {
        parent[i] = -1;
    }

    timeCounter = 0;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, visited, disc, low, parent, ap, adj);
        }
    }

    // Print articulation points in sorted order
    int found = 0;
    for (int i = 0; i < V; i++) {
        if (ap[i]) {
            printf("%d ", i);
            found = 1;
        }
    }

    if (!found)
        printf("-1");

    printf("\n");
}

// Example usage
int main() {
    V = 5;

    int adj[MAX][MAX] = {0};

    // Example graph
    // 0-1, 1-2, 2-0, 1-3, 3-4
    adj[0][1] = adj[1][0] = 1;
    adj[1][2] = adj[2][1] = 1;
    adj[2][0] = adj[0][2] = 1;
    adj[1][3] = adj[3][1] = 1;
    adj[3][4] = adj[4][3] = 1;

    findArticulationPoints(adj);

    return 0;
}
