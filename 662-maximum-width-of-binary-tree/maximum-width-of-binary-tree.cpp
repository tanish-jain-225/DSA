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
    int widthOfBinaryTree(
        TreeNode* root) // By Queue and BFS method - TC: O(N) and SC: O(N)
    {
        if (!root)
            return 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        int maxWidth = 0;
        while (!q.empty()) {
            int size = q.size();
            long long leftMost = q.front().second;
            long long rightMost = q.back().second;

            maxWidth = max(maxWidth, (int)(rightMost - leftMost + 1));

            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front().first;
                long long index = q.front().second;
                q.pop();

                if (curr->left) {
                    q.push({curr->left, 2 * (index - leftMost) + 1});
                }
                if (curr->right) {
                    q.push({curr->right, 2 * (index - leftMost) + 2});
                }
            }
        }

        return maxWidth;
    }
};