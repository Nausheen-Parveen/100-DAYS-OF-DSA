/*QUESTION:Given the head of a singly linked list, return the middle node of the linked list.
If there are two middle nodes, return the second middle node.*/

#include <stdio.h>
#include <stdlib.h>

// Structure of node
struct Node {
    int data;
    struct Node* next;
};

// Function to create new node
struct Node* newNode(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    return temp;
}

// Function to find middle node
struct Node* middleNode(struct Node* head) {
    struct Node* slow = head;
    struct Node* fast = head;

    // Move slow by 1 and fast by 2
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow; // Middle node
}

// Main function
int main() {
    struct Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);
    head->next->next->next->next->next = newNode(6);

    struct Node* mid = middleNode(head);

    printf("Middle node = %d", mid->data);

    return 0;
}
