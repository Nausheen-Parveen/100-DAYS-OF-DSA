/*In this problem, a tree is an undirected graph that is connected and has no cycles.

You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.

Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.*/

#include <stdio.h>
#define MAX 1001
int parent[MAX];

// Find with path compression
int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

// Union function
void unionSet(int x, int y) {
    int px = find(x);
    int py = find(y);
    if (px != py)
        parent[px] = py;
}

// Function to find redundant edge
void findRedundantConnection(int edges[][2], int n) {
    // Initialize parent
    for (int i = 1; i <= n; i++)
        parent[i] = i;

    int result[2];

    for (int i = 0; i < n; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        // If same parent → cycle detected
        if (find(u) == find(v)) {
            result[0] = u;
            result[1] = v;
        } else {
            unionSet(u, v);
        }
    }

    printf("Redundant edge: [%d, %d]\n", result[0], result[1]);
}

// Example usage
int main() {
    int edges[][2] = {{1,2}, {1,3}, {2,3}};
    int n = 3;

    findRedundantConnection(edges, n);

    return 0;
}
