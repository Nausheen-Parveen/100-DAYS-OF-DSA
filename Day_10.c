//Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.
#include <stdio.h>
#include <stdlib.h>

// Comparator for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n1, n2;

    scanf("%d", &n1);
    int nums1[n1];

    for (int i = 0; i < n1; i++)
        scanf("%d", &nums1[i]);

    scanf("%d", &n2);
    int nums2[n2];

    for (int i = 0; i < n2; i++)
        scanf("%d", &nums2[i]);

    // Sort both arrays
    qsort(nums1, n1, sizeof(int), compare);
    qsort(nums2, n2, sizeof(int), compare);

    int i = 0, j = 0;

    while (i < n1 && j < n2) {
        if (nums1[i] == nums2[j]) {
            printf("%d ", nums1[i]);
            i++;
            j++;
        }
        else if (nums1[i] < nums2[j]) {
            i++;
        }
        else {
            j++;
        }
    }

    return 0;
}
