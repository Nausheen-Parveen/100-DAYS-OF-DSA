/*Given the root of a binary tree, return the preorder traversal of its nodes' values.*/

#include <stdio.h>
#include <stdlib.h>

// Structure of a tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Preorder Traversal function
void preorder(struct Node* root) {
    if (root == NULL)
        return;

    printf("%d ", root->data);  // Visit root
    preorder(root->left);       // Traverse left
    preorder(root->right);      // Traverse right
}

// Main function
int main() {
    // Creating a simple tree
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Preorder Traversal: ");
    preorder(root);

    return 0;
}
