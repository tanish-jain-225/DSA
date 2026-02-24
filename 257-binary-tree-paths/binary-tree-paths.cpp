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

// Solution class to find all root-to-leaf paths in a binary tree
class Solution {
public:
    void allPaths(TreeNode* root, string path, vector<string>& paths) {
        if (!root)
            return; // base case: if the current node is null, return

        path +=
            to_string(root->val); // add the current node's value to the path

        if (!root->left && !root->right) { // if it's a leaf node
            paths.push_back(path);         // add the path to the result vector
            return;
        }

        path += "->"; // add the separator for the next node

        allPaths(root->left, path,
                 paths); // recursively find paths in the left subtree
        allPaths(root->right, path,
                 paths); // recursively find paths in the right subtree
    }

    // main function to return all root-to-leaf paths in the binary tree
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;      // vector to store the result paths
        allPaths(root, "", paths); // helper function to find all paths
        return paths;              // return the result vector
    }
};
