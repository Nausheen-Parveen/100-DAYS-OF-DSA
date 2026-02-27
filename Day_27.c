/*Given the head of a singly linked list, the task is to remove a cycle if present. A cycle exists when a node's next pointer points back to a previous node,
forming a loop. Internally, a variable pos denotes the index of the node where the cycle starts, but it is not passed as a parameter. The terminal will print
true if a cycle is removed otherwise, it will print false. write easy c code*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to remove cycle
bool removeCycle(struct Node* head) {
    if (head == NULL || head->next == NULL)
        return false;

    struct Node *slow = head, *fast = head;

    // Step 1: Detect cycle using Floyd's Algorithm
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {   // Cycle detected
            
            // Step 2: Find start of cycle
            slow = head;
            struct Node* prev = NULL;

            while (slow != fast) {
                prev = fast;
                slow = slow->next;
                fast = fast->next;
            }

            // Step 3: Remove cycle
            prev->next = NULL;

            return true;
        }
    }

    return false;  // No cycle found
}
