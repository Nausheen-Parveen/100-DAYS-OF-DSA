/*Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).*/

#include <stdio.h>
#include <stdlib.h>

// Structure for tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Queue structure
struct Queue {
    int front, rear;
    int size;
    struct Node* array[100];
};

// Initialize queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = -1;
    return q;
}

// Check if queue is empty
int isEmpty(struct Queue* q) {
    return q->front == -1;
}

// Enqueue
void enqueue(struct Queue* q, struct Node* node) {
    if (q->rear == 99) return; // overflow
    if (q->front == -1) q->front = 0;
    q->array[++q->rear] = node;
}

// Dequeue
struct Node* dequeue(struct Queue* q) {
    if (isEmpty(q)) return NULL;
    struct Node* temp = q->array[q->front];
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;
    return temp;
}

// Level Order Traversal
void levelOrder(struct Node* root) {
    if (root == NULL) return;

    struct Queue* q = createQueue();
    enqueue(q, root);

    while (!isEmpty(q)) {
        struct Node* temp = dequeue(q);
        printf("%d ", temp->data);

        if (temp->left)
            enqueue(q, temp->left);
        if (temp->right)
            enqueue(q, temp->right);
    }
}

// Driver code
int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Level Order Traversal: ");
    levelOrder(root);

    return 0;
}
