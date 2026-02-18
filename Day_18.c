//QUESTION:Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
#include <stdio.h>

int main() {
    int n;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int nums[n], answer[n];

    printf("Enter array elements:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    // Calculate product except self
    for(int i = 0; i < n; i++) {
        int product = 1;

        for(int j = 0; j < n; j++) {
            if(i != j) {
                product = product * nums[j];
            }
        }

        answer[i] = product;
    }

    // Print result
    printf("Output array:\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", answer[i]);
    }

    return 0;
}
