/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

// Solution class to populate next right pointers
class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) // Base case: if the tree is empty, return null
            return nullptr;  // If the tree is empty, return null
        queue<Node*> q;
        q.push(root);
        q.push(nullptr); // Marker for end of level

        Node* prev =
            nullptr; // To keep track of the previous node in the same level

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            if (curr == nullptr) {
                // End of current level
                if (q.size() == 0)
                    break;       // No more levels to process
                q.push(nullptr); // Marker for end of next level
                prev = nullptr;  // Reset prev for new level
            } else {
                // Connect the previous node's next to the current node
                if (prev != nullptr)
                    prev->next = curr;
                // Add left and right children to the queue
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
                prev = curr; // Update prev to the current node
            }
        }
        return root; // Return the modified tree with next pointers
    }
};
