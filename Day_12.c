/*Given an m x n matrix, return true if the matrix is Toeplitz. Otherwise, return false.

A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same elements.*/
#include <stdio.h>
#include <stdbool.h>

bool isToeplitz(int matrix[][100], int rows, int cols) {

    for (int i = 0; i < rows - 1; i++) {
        for (int j = 0; j < cols - 1; j++) {
            if (matrix[i][j] != matrix[i + 1][j + 1]) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    int rows, cols;

    scanf("%d %d", &rows, &cols);

    int matrix[100][100];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    if (isToeplitz(matrix, rows, cols))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
