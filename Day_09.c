/*Write a function that reverses a string. The input string is given as an array of characters s.

You must do this by modifying the input array in-place with O(1) extra memory.*/
#include <stdio.h>
#include <string.h>

void reverseString(char s[], int n) {
    int left = 0;
    int right = n - 1;

    while (left < right) {
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;

        left++;
        right--;
    }
}

int main() {
    char s[100];

    scanf("%s", s);   // Input string (no spaces)

    int n = strlen(s);

    reverseString(s, n);

    printf("%s\n", s);

    return 0;
}


 
