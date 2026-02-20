//QUESTION:Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

#include <stdio.h>
#include <stdlib.h>

// function for sorting
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void threeSum(int arr[], int n) {
    // sort the array
    qsort(arr, n, sizeof(int), compare);

    for(int i = 0; i < n - 2; i++) {

        // skip duplicate elements
        if(i > 0 && arr[i] == arr[i - 1])
            continue;

        int left = i + 1;
        int right = n - 1;

        while(left < right) {

            int sum = arr[i] + arr[left] + arr[right];

            if(sum == 0) {
                printf("%d %d %d\n", arr[i], arr[left], arr[right]);

                left++;
                right--;

                // skip duplicates
                while(left < right && arr[left] == arr[left - 1])
                    left++;
                while(left < right && arr[right] == arr[right + 1])
                    right--;
            }
            else if(sum < 0) {
                left++;
            }
            else {
                right--;
            }
        }
    }
}

int main() {
    int arr[] = {-1, 0, 1, 2, -1, -4};
    int n = sizeof(arr) / sizeof(arr[0]);

    threeSum(arr, n);

    return 0;
}
