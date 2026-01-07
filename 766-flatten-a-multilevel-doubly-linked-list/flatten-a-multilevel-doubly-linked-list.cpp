/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) // TC: O(N), SC: O(1)
    {
        // Base case
        if (!head)
            return head;

        // Pointer to traverse the list
        Node* curr = head;

        while (curr != nullptr) {
            if (curr->child != nullptr) {
                // Store the next node
                Node* nextNode = curr->next;
                Node* childHead = flatten(curr->child);

                // Connect curr with childHead
                curr->next = childHead;
                childHead->prev = curr;
                curr->child = nullptr; // Remove child pointer

                // Check for the end of the child list
                while (childHead->next != nullptr) {
                    childHead = childHead->next;
                }

                // Established Double Links
                if (nextNode) {
                    childHead->next = nextNode;
                    nextNode->prev = childHead;
                }
            }

            // Move to the next node
            curr = curr->next;
        }

        // Return the head of the flattened list
        return head;
    }
};