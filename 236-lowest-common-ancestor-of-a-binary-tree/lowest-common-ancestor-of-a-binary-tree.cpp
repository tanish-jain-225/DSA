/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // Function to find the lowest common ancestor of two nodes in a binary tree
    TreeNode*
    lowestCommonAncestor(TreeNode* root, TreeNode* p,
                         TreeNode* q) // Time Complexity: O(n), where n is the
                                      // number of nodes in the binary tree
    {
        // Base case: if the root is null, return null
        if (root == nullptr) {
            return nullptr;
        }

        if (root == p || root == q) {
            return root;
        }

        // Recur for left and right subtrees
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // If both left and right are not null, then one key is present in one
        // subtree and the other key is present in another subtree. So this node
        // is the lowest common ancestor.
        if (left && right) {
            return root;
        } else if (left) {
            return left;
        } else {
            return right;
        }
    }
};