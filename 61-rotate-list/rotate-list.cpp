/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : next(next), val(x) {}
 * };
 */

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        // Edge Cases
        if (head == nullptr || head->next == nullptr || k == 0) {
            return head;
        }

        // ---------------- Find Length ----------------
        int length = 0;
        ListNode* temp = head;

        while (temp != nullptr) {
            length++;
            temp = temp->next;
        }

        // Reduce extra rotations
        k %= length;

        if (k == 0) {
            return head;
        }

        // ---------------- Two Pointers ----------------
        ListNode* left = head;
        ListNode* right = head;

        // Maintain a gap of k nodes
        for (int i = 0; i < k; i++) {
            right = right->next;
        }

        // Move both pointers until right reaches the last node
        while (right->next != nullptr) {
            left = left->next;
            right = right->next;
        }

        // ---------------- Rotate List ----------------

        // Last node points to old head
        right->next = head;

        // New head is next of left
        ListNode* newHead = left->next;

        // Break the list
        left->next = nullptr;

        return newHead;
    }
};