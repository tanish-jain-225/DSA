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
    int func(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode*& ans) {

        // Base Case
        if (root == nullptr) {
            return 0;
        }

        // Check Left
        int leftPart = func(root->left, p, q, ans);

        // Check Right
        int rightPart = func(root->right, p, q, ans);

        // Check Current Node
        int selfPart = 0;

        if (root == p || root == q) {
            selfPart = 1;
        }

        // Total number of required nodes found
        int total = leftPart + rightPart + selfPart;

        // First node where both p and q are found
        if (total == 2 && ans == nullptr) {
            ans = root;
        }

        return total;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        TreeNode* ans = nullptr;

        func(root, p, q, ans);

        return ans;
    }
};