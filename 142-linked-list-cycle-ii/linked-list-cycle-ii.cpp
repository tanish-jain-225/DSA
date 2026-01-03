/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* detectCycle(ListNode* head) // Floyd's Tortoise and Hare Algorithm
    {
        ListNode* slow = head;
        ListNode* fast = head;

        // First step: Determine if a cycle exists
        while (fast && fast->next) {
            // Move pointers
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) // Cycle detected
            {
                // Second step: Find the entry point of the cycle
                slow = head; // Reset slow to head

                // Move both pointers at the same pace
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }

                return slow; // Entry point of the cycle
            }
        }

        return nullptr; // No cycle
    }
};