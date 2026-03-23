/*You are given the root of a binary search tree (BST) and an integer val.
Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.*/

#include <stdio.h>
#include <stdlib.h>

// Tree node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Search in BST
struct Node* search(struct Node* root, int val) {
    if (root == NULL || root->data == val)
        return root;

    if (val < root->data)
        return search(root->left, val);
    else
        return search(root->right, val);
}

// Inorder traversal
void inorder(struct Node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Driver code
int main() {
    struct Node* root = createNode(5);
    root->left = createNode(3);
    root->right = createNode(7);
    root->left->left = createNode(2);
    root->left->right = createNode(4);

    int val = 3;
    struct Node* result = search(root, val);

    if (result != NULL) {
        printf("Subtree rooted at %d:\n", result->data);
        inorder(result);   // print subtree
    } else {
        printf("Value not found\n");
    }

    return 0;
}
