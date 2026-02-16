/* Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.*/
#include <stdio.h>

void reverse(int nums[], int start, int end) {
    while (start < end) {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
    }
}

void rotate(int nums[], int n, int k) {
    k = k % n;  // Handle k > n

    // Step 1: Reverse whole array
    reverse(nums, 0, n - 1);

    // Step 2: Reverse first k elements
    reverse(nums, 0, k - 1);

    // Step 3: Reverse remaining elements
    reverse(nums, k, n - 1);
}

int main() {
    int n, k;

    scanf("%d", &n);
    int nums[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &nums[i]);

    scanf("%d", &k);

    rotate(nums, n, k);

    for (int i = 0; i < n; i++)
        printf("%d ", nums[i]);

    return 0;
}
