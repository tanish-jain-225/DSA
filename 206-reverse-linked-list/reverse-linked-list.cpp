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
    ListNode* reverseList(ListNode* head) {
        // Initialize three pointers
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;

        // Iterate through the list and reverse the pointers
        while (curr != NULL) {
            // Store next node
            next = curr->next; // Store next node
            curr->next = prev; // Reverse current node's pointer

            // Move pointers one position ahead
            prev = curr; // Move pointers one position ahead
            curr = next;
        }

        return prev; // New head of the reversed list
    }
};