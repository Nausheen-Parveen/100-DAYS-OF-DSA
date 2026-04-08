/*You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.*/

#include <stdio.h>

#define MAX 100

typedef struct {
    int x, y;
} Node;

Node queue[MAX * MAX];
int front = 0, rear = 0;

// Directions: up, down, left, right
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void enqueue(int x, int y) {
    queue[rear].x = x;
    queue[rear].y = y;
    rear++;
}

Node dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

int orangesRotting(int grid[MAX][MAX], int m, int n) {
    int fresh = 0;

    // Step 1: Add all rotten oranges to queue
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 2) {
                enqueue(i, j);
            }
            if (grid[i][j] == 1) {
                fresh++;
            }
        }
    }

    int minutes = 0;

    // Step 2: BFS
    while (!isEmpty() && fresh > 0) {
        int size = rear - front;

        for (int i = 0; i < size; i++) {
            Node temp = dequeue();

            for (int d = 0; d < 4; d++) {
                int nx = temp.x + dx[d];
                int ny = temp.y + dy[d];

                if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                    grid[nx][ny] = 2;
                    enqueue(nx, ny);
                    fresh--;
                }
            }
        }
        minutes++;
    }

    if (fresh == 0)
        return minutes;
    else
        return -1;
}

int main() {
    int m = 3, n = 3;

    int grid[MAX][MAX] = {
        {2,1,1},
        {1,1,0},
        {0,1,1}
    };

    int result = orangesRotting(grid, m, n);
    printf("Minimum minutes: %d\n", result);

    return 0;
}
