/*Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.*/

#include <stdio.h>
#include <stdbool.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int matrix[m][n];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    bool firstRowZero = false;
    bool firstColZero = false;

    // Check first row
    for (int j = 0; j < n; j++) {
        if (matrix[0][j] == 0)
            firstRowZero = true;
    }

    // Check first column
    for (int i = 0; i < m; i++) {
        if (matrix[i][0] == 0)
            firstColZero = true;
    }

    // Use first row & column as markers
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    // Set cells to zero based on markers
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        }
    }

    // Handle first row
    if (firstRowZero) {
        for (int j = 0; j < n; j++)
            matrix[0][j] = 0;
    }

    // Handle first column
    if (firstColZero) {
        for (int i = 0; i < m; i++)
            matrix[i][0] = 0;
    }

    // Print result
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
