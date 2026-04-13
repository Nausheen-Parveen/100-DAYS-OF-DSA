/*You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node,
and wi is the time it takes for a signal to travel from source to target.
We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal.
If it is impossible for all the n nodes to receive the signal, return -1.*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 101

// Structure for adjacency list
typedef struct Node {
    int vertex, weight;
    struct Node* next;
} Node;

Node* adj[MAX];

// Create new node
Node* createNode(int v, int w) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}

// Add edge
void addEdge(int u, int v, int w) {
    Node* newNode = createNode(v, w);
    newNode->next = adj[u];
    adj[u] = newNode;
}

// Dijkstra
int networkDelayTime(int times[][3], int timesSize, int n, int k) {
    // Initialize graph
    for (int i = 1; i <= n; i++) adj[i] = NULL;

    // Build graph
    for (int i = 0; i < timesSize; i++) {
        addEdge(times[i][0], times[i][1], times[i][2]);
    }

    int dist[MAX];
    int visited[MAX] = {0};

    // Initialize distances
    for (int i = 1; i <= n; i++)
        dist[i] = INT_MAX;

    dist[k] = 0;

    // Dijkstra
    for (int i = 1; i <= n; i++) {
        int u = -1, minDist = INT_MAX;

        // Find min distance node
        for (int j = 1; j <= n; j++) {
            if (!visited[j] && dist[j] < minDist) {
                minDist = dist[j];
                u = j;
            }
        }

        if (u == -1) break;

        visited[u] = 1;

        // Relax edges
        Node* temp = adj[u];
        while (temp != NULL) {
            int v = temp->vertex;
            int w = temp->weight;

            if (!visited[v] && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }

            temp = temp->next;
        }
    }

    // Find max time
    int maxTime = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX)
            return -1;
        if (dist[i] > maxTime)
            maxTime = dist[i];
    }

    return maxTime;
}

// Example usage
int main() {
    int times[][3] = {{2,1,1},{2,3,1},{3,4,1}};
    int n = 4;
    int k = 2;

    int result = networkDelayTime(times, 3, n, k);
    printf("Minimum time: %d\n", result);

    return 0;
}
