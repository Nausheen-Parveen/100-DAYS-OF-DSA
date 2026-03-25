/*Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two 
nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).” */

#include <stdio.h>
#include <stdlib.h>

// Structure of a node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to find LCA
struct Node* findLCA(struct Node* root, int p, int q) {
    // Base case
    if (root == NULL)
        return NULL;

    // If either p or q matches root
    if (root->data == p || root->data == q)
        return root;

    // Search in left and right subtree
    struct Node* left = findLCA(root->left, p, q);
    struct Node* right = findLCA(root->right, p, q);

    // If both sides return non-NULL, root is LCA
    if (left != NULL && right != NULL)
        return root;

    // Otherwise return non-NULL child
    if (left != NULL)
        return left;
    else
        return right;
}

// Driver code
int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    int p = 4, q = 5;

    struct Node* lca = findLCA(root, p, q);

    if (lca != NULL)
        printf("LCA of %d and %d is %d\n", p, q, lca->data);
    else
        printf("LCA not found\n");

    return 0;
}
