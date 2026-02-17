//QUESTION:Given an integer array nums, find the subarray with the largest sum, and return its sum.
#include <stdio.h>

int maxSubArray(int nums[], int n) {
    int max_sum = nums[0];
    int current_sum = nums[0];

    for(int i = 1; i < n; i++) {
        if(current_sum + nums[i] > nums[i]) {
            current_sum = current_sum + nums[i];
        } else {
            current_sum = nums[i];
        }

        if(current_sum > max_sum) {
            max_sum = current_sum;
        }
    }

    return max_sum;
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int nums[n];

    printf("Enter elements:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int result = maxSubArray(nums, n);

    printf("Maximum Subarray Sum = %d\n", result);

    return 0;
}
