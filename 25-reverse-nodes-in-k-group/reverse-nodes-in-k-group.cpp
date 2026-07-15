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
    // Reverse exactly k nodes
    ListNode* reverse(ListNode* head, int k) {

        ListNode* curr = head;
        ListNode* prev = nullptr;

        while (k--) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        return prev; // New head after reversal
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int size = k;

        if (head == nullptr)
            return head;

        ListNode* res = nullptr;

        ListNode* left = head;
        ListNode* prevleft = nullptr;

        while (true) {

            // Find right node of current group
            ListNode* right = left;

            for (int i = 0; i < size - 1; i++) {
                if (right == nullptr)
                    break;
                right = right->next;
            }

            // Less than 2 nodes left
            if (right == nullptr) {

                if (prevleft)
                    prevleft->next = left;

                if (res == nullptr)
                    res = head;

                break;
            }

            ListNode* nextleft = right->next;

            // Reverse current pair
            ListNode* newHead = reverse(left, size);

            // Connect previous pair
            if (prevleft)
                prevleft->next = newHead;

            // First reversed pair becomes answer
            if (res == nullptr)
                res = newHead;

            // Old left is now the tail
            left->next = nextleft;

            // Move previous pointer
            prevleft = left;

            // Next group
            left = nextleft;

            if (left == nullptr)
                break;
        }

        return res;
    }
};