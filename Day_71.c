/*You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int minCostConnectPoints(int** points, int pointsSize) {
    int n = pointsSize;

    int* visited = (int*)calloc(n, sizeof(int));
    int* minDist = (int*)malloc(n * sizeof(int));

    // Initialize distances as infinity
    for (int i = 0; i < n; i++) {
        minDist[i] = INT_MAX;
    }

    minDist[0] = 0; // Start from first point
    int totalCost = 0;

    for (int i = 0; i < n; i++) {
        int u = -1;

        // Find minimum distance node not visited
        for (int j = 0; j < n; j++) {
            if (!visited[j] && (u == -1 || minDist[j] < minDist[u])) {
                u = j;
            }
        }

        visited[u] = 1;
        totalCost += minDist[u];

        // Update distances using Manhattan distance
        for (int v = 0; v < n; v++) {
            if (!visited[v]) {
                int dist = abs(points[u][0] - points[v][0]) +
                           abs(points[u][1] - points[v][1]);

                if (dist < minDist[v]) {
                    minDist[v] = dist;
                }
            }
        }
    }

    free(visited);
    free(minDist);

    return totalCost;
}

// Driver Code
int main() {
    int n = 5;

    int arr[5][2] = {
        {0, 0},
        {2, 2},
        {3, 10},
        {5, 2},
        {7, 0}
    };

    int** points = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        points[i] = arr[i];
    }

    int result = minCostConnectPoints(points, n);
    printf("Minimum Cost: %d\n", result);

    free(points);

    return 0;
}
