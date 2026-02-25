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
    TreeNode* NextRightNode =
        nullptr; // Global variable to keep track of the next right node
    void flatten(TreeNode* root) // By DFS method - TC: O(N) and SC: O(H)
    {
        if (!root)
            return;
        flatten(root->right);
        flatten(root->left);
        root->right = NextRightNode;
        root->left = nullptr;
        NextRightNode = root;
    }
};