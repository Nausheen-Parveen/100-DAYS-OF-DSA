/*There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi, toi, weighti] represents a bidirectional and weighted edge between cities fromi and toi, and given the integer distanceThreshold.

Return the city with the smallest number of cities that are reachable through some path and whose distance is at most distanceThreshold, If there are multiple such cities, return the city with the greatest number.

Notice that the distance of a path connecting cities i and j is equal to the sum of the edges' weights along that path.*/

#include <stdio.h>
#include <limits.h>

#define MAX 100

int findTheCity(int n, int edges[][3], int edgesSize, int distanceThreshold) {
    int dist[MAX][MAX];

    // Step 1: Initialize distance matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = INT_MAX;
        }
    }

    // Step 2: Fill edges (bidirectional)
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        dist[u][v] = w;
        dist[v][u] = w;
    }

    // Step 3: Floyd-Warshall Algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Step 4: Find city with minimum reachable cities
    int minCount = INT_MAX;
    int resultCity = -1;

    for (int i = 0; i < n; i++) {
        int count = 0;

        for (int j = 0; j < n; j++) {
            if (i != j && dist[i][j] <= distanceThreshold) {
                count++;
            }
        }

        // Choose smaller count OR larger index in case of tie
        if (count <= minCount) {
            minCount = count;
            resultCity = i;
        }
    }

    return resultCity;
}

// Example usage
int main() {
    int n = 4;
    int edges[][3] = {
        {0,1,3},
        {1,2,1},
        {2,3,4},
        {0,3,7}
    };
    int edgesSize = 4;
    int distanceThreshold = 4;

    int result = findTheCity(n, edges, edgesSize, distanceThreshold);
    printf("City: %d\n", result);

    return 0;
}
