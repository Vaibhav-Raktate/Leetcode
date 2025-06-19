class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == NULL || left == right) return head;

        ListNode dummy(0); // Dummy node to simplify edge cases
        dummy.next = head;
        ListNode* prev = &dummy;

        // Step 1: Move `prev` to the node before `left`
        for (int i = 1; i < left; ++i) {
            prev = prev->next;
        }

        // Step 2: Reverse the sublist from left to right
        ListNode* curr = prev->next;
        ListNode* next = NULL;
        for (int i = 0; i < right - left; ++i) {
            next = curr->next;
            curr->next = next->next;
            next->next = prev->next;
            prev->next = next;
        }

        return dummy.next;
    }
};
