/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) // Function to copy the linked list
    {
        // Edge case: if the head is null, return null
        if (!head)
            return nullptr;

        // Hash map to store the mapping from original nodes to their copies
        unordered_map<Node*, Node*> m;

        // Step 1: Create a copy of each node and store the mapping
        Node* newHead = new Node(head->val);
        Node* oldTemp = head->next;
        Node* newTemp = newHead;
        m[head] = newHead;

        // Create copies of the nodes and link them using next pointers
        while (oldTemp) {
            Node* copyNode = new Node(oldTemp->val);
            m[oldTemp] = copyNode;
            newTemp->next = copyNode;
            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }

        // Step 2: Set the random pointers for the copied nodes
        oldTemp = head;
        newTemp = newHead;

        // Assign random pointers using the mapping
        while (oldTemp) {
            newTemp->random = m[oldTemp->random];
            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }

        // Return the head of the copied linked list
        return newHead;
    }
};