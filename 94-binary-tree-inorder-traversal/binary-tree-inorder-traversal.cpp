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
    vector<int> inorderTraversal(
        TreeNode* root) // By Morris Traversal method - TC: O(N) and SC: O(1)
    {
        vector<int> ans;
        TreeNode* curr = root;

        while (curr) {
            if (!curr->left) // If there is no left child, visit the current
                             // node and move to the right child
            {
                ans.push_back(curr->val);
                curr = curr->right;
            } else {
                // Find the rightmost node in the left subtree or the temporary
                // link to the current node
                TreeNode* prev = curr->left;

                while (prev->right &&
                       prev->right !=
                           curr) // Find the rightmost node in the left subtree
                                 // or the temporary link to the current node
                {
                    prev = prev->right;
                }

                if (!prev->right) // Make a temporary link to the current node
                {
                    prev->right = curr;
                    curr = curr->left;
                } else // Remove the temporary link and visit the current node
                {
                    prev->right = nullptr;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }

        // Return the result vector containing the inorder traversal of the
        // binary tree
        return ans;
    }
};