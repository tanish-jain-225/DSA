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
class Solution {
public:
    bool
    helper(TreeNode* node, TreeNode* min,
           TreeNode* max) // TC: O(n) where n is the number of nodes in the
                          // tree, SC: O(h) where h is the height of the tree
    {
        if (node == nullptr) {
            return true; // An empty tree is a valid BST
        }

        // Check conditions for the current node

        if (min != nullptr && node->val <= min->val) {
            return false; // Current node's value must be greater than min
        }

        if (max != nullptr && node->val >= max->val) {
            return false; // Current node's value must be less than max
        }

        // Recursively check the left and right subtrees with updated ranges
        return helper(node->left, min, node) && helper(node->right, node, max);
    }

    // Main function to validate the binary search tree
    bool isValidBST(TreeNode* root) {
        return helper(root, nullptr,
                      nullptr); // Start with no bounds for the root
    }
};