/*There are n rooms labeled from 0 to n - 1 and all the rooms are locked except for room 0. Your goal is to visit all the rooms. However, you cannot enter a locked room without having its key.

When you visit a room, you may find a set of distinct keys in it. Each key has a number on it, denoting which room it unlocks, and you can take all of them with you to unlock the other rooms.

Given an array rooms where rooms[i] is the set of keys that you can obtain if you visited room i, return true if you can visit all the rooms, or false otherwise.*/

#include <stdio.h>
#include <stdbool.h>

#define MAX 1000

// DFS function
void dfs(int roomsSize, int* rooms[], int roomsColSize[], bool visited[], int room) {
    visited[room] = true;

    for (int i = 0; i < roomsColSize[room]; i++) {
        int key = rooms[room][i];
        if (!visited[key]) {
            dfs(roomsSize, rooms, roomsColSize, visited, key);
        }
    }
}

// Main function to check if all rooms can be visited
bool canVisitAllRooms(int roomsSize, int* rooms[], int roomsColSize[]) {
    bool visited[MAX] = {false};

    // Start DFS from room 0
    dfs(roomsSize, rooms, roomsColSize, visited, 0);

    // Check if all rooms are visited
    for (int i = 0; i < roomsSize; i++) {
        if (!visited[i]) {
            return false;
        }
    }

    return true;
}
