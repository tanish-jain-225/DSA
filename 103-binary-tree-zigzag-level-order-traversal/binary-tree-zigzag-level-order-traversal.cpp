class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;

        if (root == NULL)
            return res;

        q.push(root);
        bool leftToRight = true;

        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> tmp(levelSize);

            int firstIdx = 0;
            int lastIdx = levelSize - 1;

            while (levelSize--) {
                TreeNode* t = q.front();
                q.pop();

                if (leftToRight) {
                    tmp[firstIdx++] = t->val;
                } else {
                    tmp[lastIdx--] = t->val;
                }

                if (t->left != NULL)
                    q.push(t->left);
                if (t->right != NULL)
                    q.push(t->right);
            }

            res.push_back(tmp);
            leftToRight = !leftToRight;
        }

        return res;
    }
};