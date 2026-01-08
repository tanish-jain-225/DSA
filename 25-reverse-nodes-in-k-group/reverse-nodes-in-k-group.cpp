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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        int count = 0;

        // check if k nodes are available
        while (count < k) {
            if (temp == nullptr)
                return head;
            temp = temp->next;
            count++;
        }

        // reverse group - recursive approach
        ListNode* prevNode = reverseKGroup(temp, k);

        // Reinitialize pointers for reversal
        temp = head;
        count = 0;
        while (count < k) {
            ListNode* nextNode = temp->next; // store next node

            temp->next = prevNode; // reverse current node's pointer

            prevNode = temp; // move prevNode to current node

            temp = nextNode; // move to next node

            count++; // increment count
        }
        return prevNode; // new head of the reversed group
    }
};