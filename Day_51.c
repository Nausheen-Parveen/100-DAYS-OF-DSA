/*Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”*/

#include <stdio.h>
#include <stdlib.h>

// Definition of a BST node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to find LCA in BST
struct Node* findLCA(struct Node* root, int p, int q) {
    if (root == NULL)
        return NULL;

    // If both values are smaller, go left
    if (p < root->data && q < root->data)
        return findLCA(root->left, p, q);

    // If both values are greater, go right
    if (p > root->data && q > root->data)
        return findLCA(root->right, p, q);

    // Otherwise, this is the LCA
    return root;
}

// Example usage
int main() {
    /*
            20
           /  \
         10    30
        / \    / \
       5  15  25  35
    */

    struct Node* root = createNode(20);
    root->left = createNode(10);
    root->right = createNode(30);
    root->left->left = createNode(5);
    root->left->right = createNode(15);
    root->right->left = createNode(25);
    root->right->right = createNode(35);

    int p = 5, q = 15;

    struct Node* lca = findLCA(root, p, q);

    if (lca != NULL)
        printf("LCA of %d and %d is: %d\n", p, q, lca->data);
    else
        printf("LCA not found\n");

    return 0;
}
