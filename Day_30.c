/*You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.*/

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

// Function to create new node
struct ListNode* newNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// Function to push elements into stack (using array)
void pushStack(struct ListNode* head, int stack[], int *top) {
    while (head != NULL) {
        stack[++(*top)] = head->val;
        head = head->next;
    }
}

// Function to add two numbers
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {

    int stack1[100], stack2[100];
    int top1 = -1, top2 = -1;

    pushStack(l1, stack1, &top1);
    pushStack(l2, stack2, &top2);

    int carry = 0;
    struct ListNode* result = NULL;

    while (top1 >= 0 || top2 >= 0 || carry) {

        int sum = carry;

        if (top1 >= 0)
            sum += stack1[top1--];

        if (top2 >= 0)
            sum += stack2[top2--];

        carry = sum / 10;

        struct ListNode* node = newNode(sum % 10);
        node->next = result;
        result = node;
    }

    return result;
}
