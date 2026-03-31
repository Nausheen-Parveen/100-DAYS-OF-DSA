/*Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).*/

#include <stdio.h>
#include <stdlib.h>

// Definition of tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to check if two trees are mirror
int isMirror(struct Node* t1, struct Node* t2) {
    // Both are NULL
    if (t1 == NULL && t2 == NULL)
        return 1;

    // One is NULL
    if (t1 == NULL || t2 == NULL)
        return 0;

    // Check data and recursive mirror condition
    return (t1->data == t2->data) &&
           isMirror(t1->left, t2->right) &&
           isMirror(t1->right, t2->left);
}

// Main function to check symmetry
int isSymmetric(struct Node* root) {
    return isMirror(root, root);
}

// Example usage
int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(4);
    root->right->left = newNode(4);
    root->right->right = newNode(3);

    if (isSymmetric(root))
        printf("Tree is symmetric\n");
    else
        printf("Tree is not symmetric\n");

    return 0;
}
