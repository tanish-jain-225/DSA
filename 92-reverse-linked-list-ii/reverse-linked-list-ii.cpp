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
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if (head == nullptr)
            return nullptr;

        if (left == right)
            return head;

        ListNode* t = head;
        ListNode* before = nullptr;

        int pos = 1;

        while (t != nullptr) {

            // Move to the left position
            if (pos < left) {
                before = t;
                t = t->next;
                pos++;
                continue;
            }

            // Reverse from left to right
            ListNode* curr = t;
            ListNode* prev = nullptr;

            int times = right - left + 1;

            while (times--) {
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            // Connect the tail of reversed part to remaining list
            t->next = curr;

            // Connect first half to reversed part
            if (before != nullptr) {
                before->next = prev;
                return head;
            }

            // If reversal starts from head
            return prev;
        }

        return head;
    }
};