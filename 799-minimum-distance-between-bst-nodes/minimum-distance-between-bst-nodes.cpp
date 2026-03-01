/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
// Solution Class
class Solution {
public:
    TreeNode* prev =
        nullptr; // To keep track of the previous node in in-order traversal

    // Function to find the minimum difference in BST
    int minDiffInBST(TreeNode* root) {
        // Base case: if the node is null, return a large value
        if (root == nullptr) {
            return INT_MAX;
        }

        // Initialize the minimum difference to a large value
        int minDiff = INT_MAX;

        // Left subtree
        if (root->left) {
            minDiff = min(minDiff, minDiffInBST(root->left));
        }

        // Process current node
        if (prev != nullptr) {
            minDiff = min(minDiff, root->val - prev->val);
        }
        prev = root; // Update the previous node to the current node

        // Right subtree
        if (root->right) {
            minDiff = min(minDiff, minDiffInBST(root->right));
        }

        // Return the minimum difference found
        return minDiff;
    }
};