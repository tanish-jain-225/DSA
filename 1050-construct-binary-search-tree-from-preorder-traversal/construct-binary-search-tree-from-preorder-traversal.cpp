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
    // Helper function to construct BST from preorder traversal
    TreeNode* helper(vector<int>& preorder, int& index,
                     int bound) // TC: O(N), SC: O(N)
    {
        if (index == preorder.size() ||
            preorder[index] >
                bound) // Base case: If index is out of bounds or current value
                       // exceeds the bound, return nullptr
        {
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[index]);
        index++; // Update index for the next recursive call
        root->left = helper(preorder, index, root->val);
        root->right = helper(preorder, index, bound);
        return root; // Return the constructed BST node
    }

    // Main function to construct BST from preorder traversal
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0; // Initialize index to keep track of the current position
                       // in the preorder vector

        // Start the recursive helper function with the initial index and an
        // upper bound of INT_MAX
        return helper(preorder, index, INT_MAX);
    }
};
