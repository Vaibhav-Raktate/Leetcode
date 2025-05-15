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
    ListNode* reverseLinkedList(ListNode* head){
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* newhead = reverseLinkedList(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = nullptr;
        return newhead;
    }

    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return true;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != nullptr && fast->next->next != nullptr){
            slow =slow->next;
            fast = fast->next;
        }

        ListNode* newhead = reverseLinkedList(slow->next);
        ListNode* first = head;
        ListNode* second  =newhead;
        while(second != nullptr){
            if(first->val != second->val){
                reverseLinkedList(newhead);
                return false;
            }
            first = first->next;
            second = second->next;
        }
        reverseLinkedList(newhead);
        return true;




        // stack<int> st;
        // ListNode* temp = head;
        // while(temp != nullptr){
        //     st.push(temp->val);
        //     temp =temp->next;
        // }
        // temp =head;
        // while(temp != nullptr){
        //     if(st.top() != temp->val) return false;
        //     temp = temp->next;
        //     st.pop();
        // }
        // return true;
    }
};
