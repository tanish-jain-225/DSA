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

// Solution class to construct the binary tree from preorder and inorder
// traversal
class Solution {
public:
    // function to search for the index of a value in the inorder array
    int search(vector<int>& inorder, int left, int right, int value) {
        for (int i = left; i <= right; i++) {
            if (inorder[i] == value)
                return i;
        }
        return -1; // return -1 if the value is not found in the inorder array
    }

    // helper function - recursively constructs the binary tree
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int& preIdx,
                     int left, int right) {
        if (left >
            right) // base case: if left index is greater than right index, then
                   // there are no elements to construct the tree
            return NULL;

        TreeNode* root = new TreeNode(preorder[preIdx]);

        int inIdx = search(inorder, left, right,
                           preorder[preIdx]); // find the index of the root in
                                              // the inorder array
        preIdx++; // move to the next index in the preorder array

        root->left =
            helper(preorder, inorder, preIdx, left,
                   inIdx - 1); // recursively construct the left subtree
        root->right = helper(preorder, inorder, preIdx, inIdx + 1,
                             right); // recursively construct the right subtree

        return root; // return the root of the constructed tree
    }

    // main function - constructs the binary tree from preorder and inorder
    // traversal
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // preIdx is the index of the current root in the preorder array
        int preIdx = 0;
        return helper(preorder, inorder, preIdx, 0, (inorder.size() - 1));
    }
};
