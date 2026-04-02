/*Given the root of a binary tree, flatten the tree into a "linked list":
The "linked list" should use the same TreeNode class where the right child pointer points to the next 
node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree. */

#include <stdio.h>
#include <stdlib.h>

// Definition of TreeNode
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to flatten the binary tree
void flatten(struct TreeNode* root) {
    if (root == NULL)
        return;

    // Flatten left and right subtrees
    flatten(root->left);
    flatten(root->right);

    // Store right subtree
    struct TreeNode* tempRight = root->right;

    // Move left subtree to right
    root->right = root->left;
    root->left = NULL;

    // Find the end of new right subtree
    struct TreeNode* curr = root;
    while (curr->right != NULL) {
        curr = curr->right;
    }

    // Attach original right subtree
    curr->right = tempRight;
}
