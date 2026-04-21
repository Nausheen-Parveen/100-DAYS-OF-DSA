/*There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network.

A critical connection is a connection that, if removed, will make some servers unable to reach some other server.

Return all critical connections in the network in any order.*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int time = 0;

// Adjacency list
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* adj[MAX];

// Add edge
void addEdge(int u, int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = u;
    newNode->next = adj[v];
    adj[v] = newNode;
}

// DFS for finding bridges
void dfs(int u, int parent, int visited[], int disc[], int low[], int n) {
    visited[u] = 1;
    disc[u] = low[u] = ++time;

    Node* temp = adj[u];

    while (temp != NULL) {
        int v = temp->vertex;

        if (!visited[v]) {
            dfs(v, u, visited, disc, low, n);

            // Update low value
            if (low[v] < low[u])
                low[u] = low[v];

            // Check for bridge
            if (low[v] > disc[u]) {
                printf("Critical Connection: %d - %d\n", u, v);
            }
        }
        else if (v != parent) {
            if (disc[v] < low[u])
                low[u] = disc[v];
        }

        temp = temp->next;
    }
}

int main() {
    int n, m;
    printf("Enter number of servers (nodes): ");
    scanf("%d", &n);

    printf("Enter number of connections (edges): ");
    scanf("%d", &m);

    // Initialize adjacency list
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
    }

    printf("Enter connections (u v):\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    int visited[MAX] = {0};
    int disc[MAX], low[MAX];

    // Run DFS for all nodes
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, -1, visited, disc, low, n);
        }
    }

    return 0;
}
