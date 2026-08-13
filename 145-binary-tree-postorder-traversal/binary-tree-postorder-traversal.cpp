class Solution {
public:
    void helper(TreeNode* root, vector<int>& ans) {

        // Base Case
        if (root == nullptr) {
            return;
        }

        // Left
        helper(root->left, ans);

        // Right
        helper(root->right, ans);

        // Root
        ans.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {

        vector<int> ans;

        helper(root, ans);

        return ans;
    }
};