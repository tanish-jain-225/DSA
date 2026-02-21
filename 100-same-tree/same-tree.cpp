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
    bool isSameTree(TreeNode* p, TreeNode* q) {

        // Base case: All in one
        if (p == nullptr || q == nullptr) {
            return p == q; // Both should be null to be the same
        }

        int isLeftSame =
            isSameTree(p->left, q->left); // Check if left subtrees are the same
        int isRightSame = isSameTree(
            p->right, q->right); // Check if right subtrees are the same

        // Both left and right subtrees must be the same, and the current node
        // values must be the same
        return isLeftSame && isRightSame && (p->val == q->val);
    } // TC: O(n) where n is the number of nodes in the smaller tree, SC: O(h)
      // where h is the height of the tree (due to recursion stack)
};