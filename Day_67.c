/*There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where
prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. 
If it is impossible to finish all courses, return an empty array.*/

#include <stdio.h>
#include <stdlib.h>

// Function to find course order
int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize) {
    
    // Step 1: Create adjacency list
    int** adj = (int**)malloc(numCourses * sizeof(int*));
    int* adjSize = (int*)calloc(numCourses, sizeof(int));
    
    for (int i = 0; i < numCourses; i++) {
        adj[i] = (int*)malloc(numCourses * sizeof(int)); // max size
    }
    
    // Step 2: In-degree array
    int* indegree = (int*)calloc(numCourses, sizeof(int));
    
    // Fill graph
    for (int i = 0; i < prerequisitesSize; i++) {
        int a = prerequisites[i][0];
        int b = prerequisites[i][1];
        
        adj[b][adjSize[b]++] = a;
        indegree[a]++;
    }
    
    // Step 3: Queue
    int* queue = (int*)malloc(numCourses * sizeof(int));
    int front = 0, rear = 0;
    
    for (int i = 0; i < numCourses; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
        }
    }
    
    // Step 4: Result array
    int* result = (int*)malloc(numCourses * sizeof(int));
    int count = 0;
    
    while (front < rear) {
        int node = queue[front++];
        result[count++] = node;
        
        for (int i = 0; i < adjSize[node]; i++) {
            int neighbor = adj[node][i];
            indegree[neighbor]--;
            
            if (indegree[neighbor] == 0) {
                queue[rear++] = neighbor;
            }
        }
    }
    
    // Step 5: Check cycle
    if (count != numCourses) {
        *returnSize = 0;
        return (int*)malloc(0); // empty array
    }
    
    *returnSize = numCourses;
    return result;
}
