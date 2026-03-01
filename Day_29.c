/*You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.*/

#include <stdio.h>
#include <stdlib.h>

// Definition of node
struct Node {
    int data;
    struct Node* next;
};

// Function to create new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to add two numbers
struct Node* addTwoNumbers(struct Node* l1, struct Node* l2) {
    struct Node dummy;   // dummy node
    struct Node* temp = &dummy;
    dummy.next = NULL;

    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry != 0) {
        int sum = carry;

        if (l1 != NULL) {
            sum += l1->data;
            l1 = l1->next;
        }

        if (l2 != NULL) {
            sum += l2->data;
            l2 = l2->next;
        }

        carry = sum / 10;

        temp->next = createNode(sum % 10);
        temp = temp->next;
    }

    return dummy.next;
}

// Function to print linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

// Example usage
int main() {
    // Number 1: 342 (2->4->3)
    struct Node* l1 = createNode(2);
    l1->next = createNode(4);
    l1->next->next = createNode(3);

    // Number 2: 465 (5->6->4)
    struct Node* l2 = createNode(5);
    l2->next = createNode(6);
    l2->next->next = createNode(4);

    struct Node* result = addTwoNumbers(l1, l2);

    printf("Sum: ");
    printList(result);

    return 0;
}
