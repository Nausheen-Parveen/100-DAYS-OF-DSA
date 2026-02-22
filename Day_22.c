//QUESTION: Given the head of a singly linked list, reverse the list, and return the reversed list.

#include <stdio.h>
#include <stdlib.h>

// Structure of node
struct Node {
    int data;
    struct Node* next;
};

// Function to reverse linked list
struct Node* reverseList(struct Node* head) {
    struct Node *prev = NULL;
    struct Node *curr = head;
    struct Node *next = NULL;

    while(curr != NULL) {
        next = curr->next;   // store next node
        curr->next = prev;   // reverse link
        prev = curr;         // move prev forward
        curr = next;         // move curr forward
    }

    return prev; // new head
}

// Function to print list
void display(struct Node* head) {
    while(head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Main function
int main() {

    // Creating linked list: 1->2->3->4
    struct Node *head = NULL;
    struct Node *n1 = malloc(sizeof(struct Node));
    struct Node *n2 = malloc(sizeof(struct Node));
    struct Node *n3 = malloc(sizeof(struct Node));
    struct Node *n4 = malloc(sizeof(struct Node));

    n1->data = 1; n1->next = n2;
    n2->data = 2; n2->next = n3;
    n3->data = 3; n3->next = n4;
    n4->data = 4; n4->next = NULL;

    head = n1;

    printf("Original List:\n");
    display(head);

    head = reverseList(head);

    printf("Reversed List:\n");
    display(head);

    return 0;
}
