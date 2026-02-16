//You are given an array arr[] of size n - 1 that contains distinct integers in the range from 1 to n (inclusive). This array represents a permutation of the integers from 1 to n with one element missing. Your task is to identify and return the missing element
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);   // n is the range (1 to n)

    int arr[n - 1];

    // Read n-1 elements
    for(int i = 0; i < n - 1; i++) {
        scanf("%d", &arr[i]);
    }

    int expectedSum = n * (n + 1) / 2;
    int actualSum = 0;

    for(int i = 0; i < n - 1; i++) {
        actualSum += arr[i];
    }

    int missing = expectedSum - actualSum;

    printf("%d\n", missing);

    return 0;
}
