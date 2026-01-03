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
    bool hasCycle(ListNode* head) // Floyd's Tortoise and Hare Algorithm
    {
        // Initialize two pointers
        ListNode* slow = head;
        ListNode* fast = head;

        // Traverse the list
        while (fast && fast->next) {
            slow = slow->next;       // Move slow pointer by 1
            fast = fast->next->next; // Move fast pointer by 2

            // Check if they meet
            if (slow == fast) {
                return true; // Cycle detected
            }
        }

        return false; // No cycle
    }
};