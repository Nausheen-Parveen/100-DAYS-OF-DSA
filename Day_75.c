/*There is an undirected graph with n nodes, where each node is numbered between 0 and n - 1. You are given a 2D array graph, where graph[u] is an array of nodes that node u is adjacent to. More formally, for each v in graph[u], there is an undirected edge between node u and node v. The graph has the following properties:

There are no self-edges (graph[u] does not contain u).
There are no parallel edges (graph[u] does not contain duplicate values).
If v is in graph[u], then u is in graph[v] (the graph is undirected).
The graph may not be connected, meaning there may be two nodes u and v such that there is no path between them.
A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the graph connects a node in set A and a node in set B.

Return true if and only if it is bipartite.*/

#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int graph[MAX][MAX];  // adjacency matrix
int color[MAX];
int n;

// DFS function
bool dfs(int node, int c) {
    color[node] = c;

    for (int i = 0; i < n; i++) {
        if (graph[node][i] == 1) {
            // If not colored
            if (color[i] == -1) {
                if (!dfs(i, 1 - c))
                    return false;
            }
            // If same color → not bipartite
            else if (color[i] == c) {
                return false;
            }
        }
    }
    return true;
}

// Main function
bool isBipartite() {
    for (int i = 0; i < n; i++)
        color[i] = -1;

    for (int i = 0; i < n; i++) {
        if (color[i] == -1) {
            if (!dfs(i, 0))
                return false;
        }
    }
    return true;
}

int main() {
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    if (isBipartite())
        printf("Graph is Bipartite\n");
    else
        printf("Graph is NOT Bipartite\n");

    return 0;
}
