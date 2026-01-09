/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // Base case: if the list is empty or has only one node
        if (!head || !head->next) {
            return head;
        }

        // Nodes to be swapped
        ListNode* first = head;
        ListNode* second = head->next;
        ListNode* prev = nullptr;

        // Iterating through the list and swapping nodes in pairs
        while (first && second) // Ensure both nodes exist for swapping
        {
            ListNode* third = second->next; // Store the next pair's first node

            // Swapping Logic

            // Adjusting pointers to swap the nodes
            second->next = first;
            first->next = third;

            // Re-linking the previous pair - Check if prev is not null
            if (prev) {
                prev->next =
                    second; // Link previous pair to the current swapped pair
            } else {
                head = second; // Update head for the first swap
            }

            // Move to the next pair
            prev = first;
            first = third;

            // Update second for the next iteration - Check if first is not null
            if (first) {
                second = first->next;
            } else {
                break;
            }
        }

        // Return the new head of the modified list
        return head;
    }
};