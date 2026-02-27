/*Design your implementation of the linked list. You can choose to use a singly or doubly linked list.
A node in a singly linked list should have two attributes: val and next. val is the value of the current node, and next is a pointer/reference to the next node.
If you want to use the doubly linked list, you will need one more attribute prev to indicate the previous node in the linked list. Assume all nodes in the linked list are 0-indexed.*/

#include <stdio.h>
#include <stdlib.h>

// Define Node
struct Node {
    int val;
    struct Node* next;
};

// Define Linked List
struct LinkedList {
    struct Node* head;
};

// Initialize list
void init(struct LinkedList* list) {
    list->head = NULL;
}

// Get value at index
int get(struct LinkedList* list, int index) {
    struct Node* temp = list->head;
    int i = 0;

    while (temp != NULL) {
        if (i == index)
            return temp->val;
        temp = temp->next;
        i++;
    }
    return -1; // Invalid index
}

// Add at head
void addAtHead(struct LinkedList* list, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->next = list->head;
    list->head = newNode;
}

// Add at tail
void addAtTail(struct LinkedList* list, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
        return;
    }

    struct Node* temp = list->head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Add at index
void addAtIndex(struct LinkedList* list, int index, int val) {
    if (index == 0) {
        addAtHead(list, val);
        return;
    }

    struct Node* temp = list->head;
    int i = 0;

    while (temp != NULL && i < index - 1) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) return;

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete at index
void deleteAtIndex(struct LinkedList* list, int index) {
    if (list->head == NULL) return;

    if (index == 0) {
        struct Node* temp = list->head;
        list->head = temp->next;
        free(temp);
        return;
    }

    struct Node* temp = list->head;
    int i = 0;

    while (temp->next != NULL && i < index - 1) {
        temp = temp->next;
        i++;
    }

    if (temp->next == NULL) return;

    struct Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
}
