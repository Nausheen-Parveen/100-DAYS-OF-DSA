/*implement a Queue using two stacks.

Approach:
- Use two stacks: stack1 (input) and stack2 (output).
- Push operation inserts into stack1.
- For pop/peek, move all elements from stack1 to stack2, access the front element, then move elements back.
- This ensures FIFO behavior using LIFO stacks.*/

#include <stdio.h>
#define MAX 100

int stack1[MAX], stack2[MAX];
int top1 = -1, top2 = -1;

int isEmptyStack1() {
    return top1 == -1;
}

void push(int x) {
    stack1[++top1] = x;
}

int pop() {
    // Move all elements to stack2
    while (top1 != -1) {
        stack2[++top2] = stack1[top1--];
    }

    int removed = stack2[top2--];

    // Move back to stack1
    while (top2 != -1) {
        stack1[++top1] = stack2[top2--];
    }

    return removed;
}

int peek() {
    while (top1 != -1) {
        stack2[++top2] = stack1[top1--];
    }

    int front = stack2[top2];

    while (top2 != -1) {
        stack1[++top1] = stack2[top2--];
    }

    return front;
}

int empty() {
    return top1 == -1;
}
