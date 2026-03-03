/*Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:
Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.*/

#include <stdio.h>
#include <string.h>

#define MAX 100

int isValid(char s[]) {
    char stack[MAX];
    int top = -1;   // stack is empty

    for(int i = 0; s[i] != '\0'; i++) {
        
        // If opening bracket → push
        if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
            stack[++top] = s[i];
        }
        
        // If closing bracket
        else {
            // If stack empty → invalid
            if(top == -1) {
                return 0;
            }

            // Check matching
            if((s[i] == ')' && stack[top] == '(') ||
               (s[i] == '}' && stack[top] == '{') ||
               (s[i] == ']' && stack[top] == '[')) {
                
                top--;  // pop
            }
            else {
                return 0;
            }
        }
    }

    // If stack empty → valid
    if(top == -1)
        return 1;
    else
        return 0;
}

int main() {
    char s[MAX];

    printf("Enter string: ");
    scanf("%s", s);

    if(isValid(s))
        printf("Valid String\n");
    else
        printf("Invalid String\n");

    return 0;
}
