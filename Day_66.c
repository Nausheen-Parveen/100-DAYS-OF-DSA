/*There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to perform DFS and detect cycle
bool dfs(int node, int** graph, int* graphColSize, int* visited, int* recStack) {
    // If node is in recursion stack → cycle detected
    if (recStack[node])
        return true;

    // If already visited → no need to check again
    if (visited[node])
        return false;

    // Mark visited and add to recursion stack
    visited[node] = 1;
    recStack[node] = 1;

    // Visit all neighbors
    for (int i = 0; i < graphColSize[node]; i++) {
        int neighbor = graph[node][i];
        if (dfs(neighbor, graph, graphColSize, visited, recStack))
            return true;
    }

    // Remove from recursion stack
    recStack[node] = 0;
    return false;
}

// Main function
bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    
    // Create adjacency list
    int** graph = (int**)malloc(numCourses * sizeof(int*));
    int* graphColSize = (int*)calloc(numCourses, sizeof(int));

    // Initialize graph
    for (int i = 0; i < numCourses; i++) {
        graph[i] = (int*)malloc(numCourses * sizeof(int)); // max possible
    }

    // Build graph
    for (int i = 0; i < prerequisitesSize; i++) {
        int a = prerequisites[i][0];
        int b = prerequisites[i][1];
        graph[b][graphColSize[b]++] = a; // edge b → a
    }

    // Visited and recursion stack arrays
    int* visited = (int*)calloc(numCourses, sizeof(int));
    int* recStack = (int*)calloc(numCourses, sizeof(int));

    // Check each course
    for (int i = 0; i < numCourses; i++) {
        if (dfs(i, graph, graphColSize, visited, recStack)) {
            return false; // cycle found
        }
    }

    return true; // no cycle → all courses can be finished
}
