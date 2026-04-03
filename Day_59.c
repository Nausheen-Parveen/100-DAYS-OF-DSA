/*Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.*/

#include <stdio.h>
#include <stdlib.h>

// Definition of tree node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to find index of value in inorder array
int search(int inorder[], int start, int end, int val) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == val)
            return i;
    }
    return -1;
}

// Recursive function to build tree
struct TreeNode* buildTreeHelper(int inorder[], int postorder[], 
                                int inStart, int inEnd, int* postIndex) {
    
    if (inStart > inEnd)
        return NULL;

    // Last element in postorder is root
    int rootVal = postorder[*postIndex];
    (*postIndex)--;

    struct TreeNode* root = newNode(rootVal);

    // If only one node, return it
    if (inStart == inEnd)
        return root;

    // Find root in inorder
    int inIndex = search(inorder, inStart, inEnd, rootVal);

    // Build right subtree first
    root->right = buildTreeHelper(inorder, postorder, inIndex + 1, inEnd, postIndex);
    root->left = buildTreeHelper(inorder, postorder, inStart, inIndex - 1, postIndex);

    return root;
}

// Main function to build tree
struct TreeNode* buildTree(int inorder[], int postorder[], int n) {
    int postIndex = n - 1;
    return buildTreeHelper(inorder, postorder, 0, n - 1, &postIndex);
}

// Function to print preorder (for verification)
void preorder(struct TreeNode* root) {
    if (root == NULL)
        return;
    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}

// Driver code
int main() {
    int inorder[] = {9, 3, 15, 20, 7};
    int postorder[] = {9, 15, 7, 20, 3};
    int n = sizeof(inorder) / sizeof(inorder[0]);

    struct TreeNode* root = buildTree(inorder, postorder, n);

    printf("Preorder traversal of constructed tree:\n");
    preorder(root);

    return 0;
}
