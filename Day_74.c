/*There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.*/

#include <stdio.h>

#define MAX 100

void dfs(int isConnected[MAX][MAX], int visited[], int n, int city) {
    visited[city] = 1;

    for (int j = 0; j < n; j++) {
        if (isConnected[city][j] == 1 && !visited[j]) {
            dfs(isConnected, visited, n, j);
        }
    }
}

int findCircleNum(int isConnected[MAX][MAX], int n) {
    int visited[MAX] = {0};
    int provinces = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(isConnected, visited, n, i);
            provinces++;   // new province found
        }
    }

    return provinces;
}

int main() {
    int n;

    printf("Enter number of cities: ");
    scanf("%d", &n);

    int isConnected[MAX][MAX];

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &isConnected[i][j]);
        }
    }

    int result = findCircleNum(isConnected, n);
    printf("Number of provinces: %d\n", result);

    return 0;
}
