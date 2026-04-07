/*You are given an image represented by an m x n grid of integers image, where image[i][j] represents the pixel value of the image. You are also given three integers sr, sc, and color. Your task is to perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill:

Begin with the starting pixel and change its color to color.
Perform the same process for each pixel that is directly adjacent (pixels that share a side with the original pixel, either horizontally or vertically) and shares the same color as the starting pixel.
Keep repeating this process by checking neighboring pixels of the updated pixels and modifying their color if it matches the original color of the starting pixel.
The process stops when there are no more adjacent pixels of the original color to update.
Return the modified image after performing the flood fill.*/

#include <stdio.h>

#define MAX 100

void floodFill(int image[MAX][MAX], int sr, int sc, int newColor, int originalColor, int m, int n) {
    // Boundary check
    if (sr < 0 || sr >= m || sc < 0 || sc >= n)
        return;

    // If color doesn't match or already filled
    if (image[sr][sc] != originalColor || image[sr][sc] == newColor)
        return;

    // Fill the color
    image[sr][sc] = newColor;

    // Recursively fill neighbors (4 directions)
    floodFill(image, sr + 1, sc, newColor, originalColor, m, n); // Down
    floodFill(image, sr - 1, sc, newColor, originalColor, m, n); // Up
    floodFill(image, sr, sc + 1, newColor, originalColor, m, n); // Right
    floodFill(image, sr, sc - 1, newColor, originalColor, m, n); // Left
}

int main() {
    int m, n;
    int image[MAX][MAX];

    printf("Enter rows and columns: ");
    scanf("%d %d", &m, &n);

    printf("Enter image values:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &image[i][j]);
        }
    }

    int sr, sc, color;
    printf("Enter starting row, column and new color: ");
    scanf("%d %d %d", &sr, &sc, &color);

    int originalColor = image[sr][sc];

    // If original color is same as new color, no need to process
    if (originalColor != color) {
        floodFill(image, sr, sc, color, originalColor, m, n);
    }

    printf("Updated Image:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    return 0;
}
