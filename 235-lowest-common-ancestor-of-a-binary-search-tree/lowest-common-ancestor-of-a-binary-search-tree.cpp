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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p,
                                   TreeNode* q) // TC: O(h), SC: O(1)
    {
        // Base case: if the root is null, return null
        if (root == nullptr)
            return nullptr;

        if (p->val < root->val &&
            q->val < root->val) // If both p and q are smaller than root, then
                                // LCA lies in left
        {
            // If both p and q are smaller than root, then LCA lies in left
            return lowestCommonAncestor(root->left, p, q);
        } else if (p->val > root->val &&
                   q->val > root->val) // If both p and q are greater than root,
                                       // then LCA lies in right
        {
            // If both p and q are greater than root, then LCA lies in right
            return lowestCommonAncestor(root->right, p, q);
        } else // If one of p or q is on one side and the other is on the other
               // side, then root is LCA
        {
            // If one of p or q is on one side and the other is on the other
            // side, then root is LCA
            return root;
        }
    }
};