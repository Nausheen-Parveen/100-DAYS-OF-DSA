/*Given the root of a binary tree, return the sum of all left leaves.
A leaf is a node with no children. A left leaf is a leaf that is the left child of another node*/

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

// Function to find sum of left leaves
int sumOfLeftLeaves(struct Node* root) {
    if (root == NULL)
        return 0;

    int sum = 0;

    // Check if left child exists and is a leaf
    if (root->left != NULL &&
        root->left->left == NULL &&
        root->left->right == NULL) {
        sum += root->left->data;
    }

    // Recur for left and right subtree
    sum += sumOfLeftLeaves(root->left);
    sum += sumOfLeftLeaves(root->right);

    return sum;
}

// Driver code
int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->right = createNode(6);

    printf("Sum of Left Leaves: %d\n", sumOfLeftLeaves(root));

    return 0;
}
