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

// Solution Class
class BSTIterator {
public:
    stack<TreeNode*> st; // Stack to store the nodes for in-order traversal

    void StoreLeftNodes(TreeNode* node) // Helper function to store all left
                                        // nodes of the given node in the stack
    {
        while (node) {
            st.push(node);
            node = node->left;
        }
    }

    BSTIterator(TreeNode* root) // Constructor to initialize the stack with the
                                // leftmost path of the tree
    {

        StoreLeftNodes(root);
    }

    /** @return the next smallest number */
    int
    next() // Returns the next smallest number in the BST by popping the top
           // node from the stack and storing its right child's leftmost path
    {
        TreeNode* topNode = st.top();
        st.pop();
        StoreLeftNodes(topNode->right);
        return topNode->val;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() // Checks if there are more nodes to visit by checking if the
                   // stack is not empty
    {
        return st.size() > 0;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */