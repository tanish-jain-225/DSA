/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// Solution class to recover the binary search tree
class Solution
{
public:
    TreeNode *first = nullptr, *second = nullptr, *prev = nullptr; // Pointers to track the nodes that need to be swapped and the previous node during inorder traversal

    // Function to perform inorder traversal and identify the two nodes that are out of order
    void inOrder(TreeNode *root)
    {
        if (root == nullptr)
            return;

        inOrder(root->left); // Traverse left subtree

        // Check for the first violation of the BST property
        if (prev != nullptr && prev->val > root->val)
        {
            if (first == nullptr)
                first = prev; // First node to be swapped
            second = root;    // Second node to be swapped
        }
        prev = root; // Update previous node

        inOrder(root->right); // Traverse right subtree
    }

    // Function to recover the BST by swapping the values of the two incorrect nodes
    void recoverTree(TreeNode *root)
    {
        // Perform inorder traversal to identify the swapped nodes
        inOrder(root);

        // Swap the values of the two nodes
        if (first && second)
        {
            swap(first->val, second->val);
        }
    }

    // Function to get inorder traversal of the tree
    void getInOrder(TreeNode *root, vector<int> &arr)
    {
        if (root == nullptr)
            return;

        getInOrder(root->left, arr);
        arr.push_back(root->val);
        getInOrder(root->right, arr);
    }
};
