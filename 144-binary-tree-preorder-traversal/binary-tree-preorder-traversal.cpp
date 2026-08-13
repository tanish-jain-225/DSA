class Solution {
public:
    void helper(TreeNode* root, vector<int>& ans) {

        // Base Case
        if (root == nullptr) {
            return;
        }

        // Root
        ans.push_back(root->val);

        // Left
        helper(root->left, ans);

        // Right
        helper(root->right, ans);
    }

    vector<int> preorderTraversal(TreeNode* root) {

        vector<int> ans;

        helper(root, ans);

        return ans;
    }
};