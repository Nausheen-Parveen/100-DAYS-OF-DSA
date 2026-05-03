/*A peak element is an element that is strictly greater than its neighbors.

Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.

You must write an algorithm that runs in O(log n) time*/

#include <stdio.h>

int findPeakElement(int* nums, int numsSize) {
    int left = 0, right = numsSize - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] < nums[mid + 1]) {
            // Peak is in the right half
            left = mid + 1;
        } else {
            // Peak is in the left half (including mid)
            right = mid;
        }
    }

    // left == right → peak index
    return left;
}

int main() {
    int nums[] = {1, 2, 3, 1};
    int n = sizeof(nums) / sizeof(nums[0]);

    int peakIndex = findPeakElement(nums, n);
    printf("Peak Element Index: %d\n", peakIndex);

    return 0;
}
