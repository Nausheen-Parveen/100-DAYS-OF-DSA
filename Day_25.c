/*QUESTION:Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.
There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following 
the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed).
It is -1 if there is no cycle. Note that pos is not passed as a parameter.
Do not modify the linked list.*/

#include <stdio.h>
#include <stdlib.h>

// Definition of linked list node
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to detect cycle and return starting node
struct ListNode *detectCycle(struct ListNode *head) {
    
    if (head == NULL || head->next == NULL)
        return NULL;

    struct ListNode *slow = head;
    struct ListNode *fast = head;

    // Step 1: Detect if cycle exists
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {   // Cycle detected
            
            // Step 2: Find starting node of cycle
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;   // Start of cycle
        }
    }

    return NULL;  // No cycle
}

