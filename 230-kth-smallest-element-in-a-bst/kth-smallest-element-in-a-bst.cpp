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
    int preOrder = 0; // Counter for the number of nodes visited

    int kthSmallest(TreeNode* root,
                    int k) // TC: O(N) where N is the number of nodes in the
                           // BST, SC: O(H) where H is the height of the BST
    {
        if (root == nullptr)
            return -1; // Base case: if the node is null, return -1

        // Traverse the left subtree
        if (root->left) {
            int left = kthSmallest(
                root->left,
                k); // Recursively find the kth smallest in the left subtree
            if (left != -1)
                return left; // If the kth smallest is found in the left
                             // subtree, return it
        }

        if (preOrder + 1 == k)
            return root->val; // If the current node is the kth smallest, return
                              // its value

        preOrder++; // Increment the counter for the current node

        // Traverse the right subtree
        if (root->right) {
            int right = kthSmallest(
                root->right,
                k); // Recursively find the kth smallest in the right subtree
            if (right != -1)
                return right; // If the kth smallest is found in the right
                              // subtree, return it
        }

        return -1; // If the kth smallest is not found in either subtree, return
                   // -1
    }
};