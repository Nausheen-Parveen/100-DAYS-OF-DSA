//QUESTION:Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.
#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

int maxSubarraySumCircular(int nums[], int n) {
    int total = 0;
    int currMax = nums[0], maxSum = nums[0];
    int currMin = nums[0], minSum = nums[0];

    for (int i = 0; i < n; i++) {
        total += nums[i];

        if (i != 0) {
            currMax = max(nums[i], currMax + nums[i]);
            maxSum = max(maxSum, currMax);

            currMin = min(nums[i], currMin + nums[i]);
            minSum = min(minSum, currMin);
        }
    }

    // If all numbers are negative
    if (maxSum < 0)
        return maxSum;

    return max(maxSum, total - minSum);
}

int main() {
    int nums[] = {5, -3, 5};
    int n = sizeof(nums) / sizeof(nums[0]);

    printf("Maximum Circular Subarray Sum: %d\n", 
            maxSubarraySumCircular(nums, n));

    return 0;
}
