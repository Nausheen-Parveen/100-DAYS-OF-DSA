/*Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
Implement the MinStack class:
MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

// MinStack structure
struct MinStack {
    int stack[MAX];
    int minStack[MAX];
    int top;
};

// Initialize stack
void initStack(struct MinStack* s) {
    s->top = -1;
}

// Push operation
void push(struct MinStack* s, int val) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }

    s->top++;
    s->stack[s->top] = val;

    // If first element
    if (s->top == 0)
        s->minStack[s->top] = val;
    else {
        // Store minimum till now
        if (val < s->minStack[s->top - 1])
            s->minStack[s->top] = val;
        else
            s->minStack[s->top] = s->minStack[s->top - 1];
    }
}

// Pop operation
void pop(struct MinStack* s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        return;
    }
    s->top--;
}

// Top operation
int top(struct MinStack* s) {
    if (s->top == -1) {
        printf("Stack is Empty\n");
        return -1;
    }
    return s->stack[s->top];
}

// Get Minimum
int getMin(struct MinStack* s) {
    if (s->top == -1) {
        printf("Stack is Empty\n");
        return -1;
    }
    return s->minStack[s->top];
}

// Main function
int main() {
    struct MinStack s;
    initStack(&s);

    push(&s, 5);
    push(&s, 3);
    push(&s, 7);
    push(&s, 2);

    printf("Top element: %d\n", top(&s));
    printf("Minimum element: %d\n", getMin(&s));

    pop(&s);
    printf("After pop:\n");
    printf("Top element: %d\n", top(&s));
    printf("Minimum element: %d\n", getMin(&s));

    return 0;
}

