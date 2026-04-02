/*Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree
and inorder is the inorder traversal of the same tree,construct and return the binary tree.*/

#include <stdio.h>
#include <stdlib.h>

// Tree node structure
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

// Find index of value in inorder array
int findIndex(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

// Recursive function to build tree
struct TreeNode* buildTreeHelper(int preorder[], int inorder[], int* preIndex, int inStart, int inEnd) {
    if (inStart > inEnd)
        return NULL;

    // Pick current node from preorder
    int rootVal = preorder[*preIndex];
    (*preIndex)++;

    struct TreeNode* root = newNode(rootVal);

    // If leaf node
    if (inStart == inEnd)
        return root;

    // Find root in inorder
    int inIndex = findIndex(inorder, inStart, inEnd, rootVal);

    // Build left and right subtrees
    root->left = buildTreeHelper(preorder, inorder, preIndex, inStart, inIndex - 1);
    root->right = buildTreeHelper(preorder, inorder, preIndex, inIndex + 1, inEnd);

    return root;
}

// Main function
struct TreeNode* buildTree(int preorder[], int inorder[], int size) {
    int preIndex = 0;
    return buildTreeHelper(preorder, inorder, &preIndex, 0, size - 1);
}
