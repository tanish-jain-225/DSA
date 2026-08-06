class Solution {
public:
    ListNode* detectCycle(ListNode* head) {

        if (head == NULL || head->next == NULL)
            return NULL;

        ListNode* slow = head;
        ListNode* fast = head;

        // Detect cycle
        while (fast != NULL && fast->next != NULL) {

            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
                break;
        }

        // No cycle
        if (fast == NULL || fast->next == NULL)
            return NULL;

        // Reset slow
        slow = head;

        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};