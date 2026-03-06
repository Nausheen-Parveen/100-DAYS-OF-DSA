/*You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

Evaluate the expression. Return an integer that represents the value of the expression.

Note that:

The valid operators are '+', '-', '*', and '/'.
Each operand may be an integer or another expression.
The division between two integers always truncates toward zero.
There will not be any division by zero.
The input represents a valid arithmetic expression in a reverse polish notation.
The answer and all the intermediate calculations can be represented in a 32-bit integer*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int evalRPN(char *tokens[], int n) {
    int stack[1000];
    int top = -1;

    for(int i = 0; i < n; i++) {

        if(strcmp(tokens[i], "+") == 0) {
            int b = stack[top--];
            int a = stack[top--];
            stack[++top] = a + b;
        }

        else if(strcmp(tokens[i], "-") == 0) {
            int b = stack[top--];
            int a = stack[top--];
            stack[++top] = a - b;
        }

        else if(strcmp(tokens[i], "*") == 0) {
            int b = stack[top--];
            int a = stack[top--];
            stack[++top] = a * b;
        }

        else if(strcmp(tokens[i], "/") == 0) {
            int b = stack[top--];
            int a = stack[top--];
            stack[++top] = a / b;
        }

        else {
            stack[++top] = atoi(tokens[i]);
        }
    }

    return stack[top];
}

int main() {
    char *tokens[] = {"2","1","+","3","*"};
    int n = 5;

    printf("Result = %d", evalRPN(tokens, n));

    return 0;
}
