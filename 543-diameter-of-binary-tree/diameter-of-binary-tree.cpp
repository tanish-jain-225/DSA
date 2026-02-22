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
    // Optimized version of the diameter calculation using a single traversal
    int ans = 0; // Variable to store the maximum diameter found so far
    int heightDiam(TreeNode* root) {
        if (root == NULL)
            return 0;

        int leftHeight = heightDiam(root->left);
        int rightHeight = heightDiam(root->right);

        int diameter =
            leftHeight +
            rightHeight;          // Calculate the diameter at the current node
        ans = max(diameter, ans); // Update the maximum diameter found so far
        return max(leftHeight, rightHeight) +
               1; // Return the height of the current node
    }

    int diameterOfBinaryTree(
        TreeNode* root) // TC: O(n) where n is the number of nodes in the tree,
                        // SC: O(h) where h is the height of the tree
    {
        heightDiam(root); // Start the diameter calculation from the root node
        return ans;       // Return the maximum diameter found
    }
};