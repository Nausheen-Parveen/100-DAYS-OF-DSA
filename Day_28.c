//Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to check palindrome
bool isPalindrome(struct Node* head) {
    int arr[1000];   // assuming max size 1000
    int i = 0;
    
    struct Node* temp = head;
    
    // Store elements in array
    while (temp != NULL) {
        arr[i++] = temp->data;
        temp = temp->next;
    }
    
    // Compare from start and end
    int start = 0;
    int end = i - 1;
    
    while (start < end) {
        if (arr[start] != arr[end]) {
            return false;
        }
        start++;
        end--;
    }
    
    return true;
}

// Function to insert at end
struct Node* insert(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Main function
int main() {
    struct Node* head = NULL;

    // Example: 1 -> 2 -> 2 -> 1
    head = insert(head, 1);
    head = insert(head, 2);
    head = insert(head, 2);
    head = insert(head, 1);

    if (isPalindrome(head))
        printf("True - It is a Palindrome\n");
    else
        printf("False - Not a Palindrome\n");

    return 0;
}
