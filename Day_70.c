/*There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that 
there is a flight from city fromi to city toi with cost pricei.
You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1. */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

// Structure for adjacency list
typedef struct Node {
    int city;
    int cost;
    struct Node* next;
} Node;

// Create new node
Node* createNode(int city, int cost) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->city = city;
    newNode->cost = cost;
    newNode->next = NULL;
    return newNode;
}

// Add edge to graph
void addEdge(Node* adj[], int u, int v, int cost) {
    Node* newNode = createNode(v, cost);
    newNode->next = adj[u];
    adj[u] = newNode;
}

// Queue structure
typedef struct {
    int city;
    int cost;
} QueueNode;

QueueNode queue[MAX * MAX];

int findCheapestPrice(int n, int flights[][3], int flightsSize, int src, int dst, int k) {
    
    Node* adj[MAX] = {NULL};

    // Build graph
    for (int i = 0; i < flightsSize; i++) {
        addEdge(adj, flights[i][0], flights[i][1], flights[i][2]);
    }

    int dist[MAX];
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
    }

    int front = 0, rear = 0;

    // Start from source
    queue[rear++] = (QueueNode){src, 0};
    dist[src] = 0;

    int stops = 0;

    while (front < rear && stops <= k) {
        int size = rear - front;

        for (int i = 0; i < size; i++) {
            QueueNode curr = queue[front++];
            int city = curr.city;
            int cost = curr.cost;

            Node* temp = adj[city];

            while (temp) {
                int nextCity = temp->city;
                int newCost = cost + temp->cost;

                if (newCost < dist[nextCity]) {
                    dist[nextCity] = newCost;
                    queue[rear++] = (QueueNode){nextCity, newCost};
                }

                temp = temp->next;
            }
        }

        stops++;
    }

    return (dist[dst] == INT_MAX) ? -1 : dist[dst];
}

// Driver code
int main() {
    int flights[][3] = {
        {0, 1, 100},
        {1, 2, 100},
        {0, 2, 500}
    };

    int n = 3;
    int src = 0, dst = 2, k = 1;

    int result = findCheapestPrice(n, flights, 3, src, dst, k);

    printf("Cheapest Price: %d\n", result);

    return 0;
}
