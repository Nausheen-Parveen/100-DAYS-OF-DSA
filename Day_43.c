/*Given the root of a binary tree, return the inorder traversal of its nodes' values.*/

#include <stdio.h>
#include <stdlib.h>

// Definition of a node
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

// Inorder Traversal function
void inorder(struct Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);      // Visit left subtree
    printf("%d ", root->data); // Visit root
    inorder(root->right);     // Visit right subtree
}

// Main function
int main() {
    // Creating a simple tree manually
    struct Node* root = createNode(1);
    root->right = createNode(2);
    root->right->left = createNode(3);

    printf("Inorder Traversal: ");
    inorder(root);

    return 0;
}
