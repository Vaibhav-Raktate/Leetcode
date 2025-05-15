/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    private static ListNode reverseLinkedList(ListNode head){
        if(head == null || head.next == null) return head;
        ListNode newhead = reverseLinkedList(head.next);
        ListNode front = head.next;
        front.next = head;
        head.next = null;
        return newhead;
    }

    
    public boolean isPalindrome(ListNode head) {

        if(head == null || head.next == null) return true;
        ListNode slow = head;
        ListNode fast = head;
        while(fast.next != null && fast.next.next != null){
            slow =slow.next;
            fast = fast.next.next;
        }

        ListNode newhead = reverseLinkedList(slow.next);
        ListNode first = head;
        ListNode second  =newhead;
        while(second != null){
            if(first.val != second.val){
                reverseLinkedList(newhead);
                return false;
            }
            first = first.next;
            second = second.next;
        }
        reverseLinkedList(newhead);
        return true;


        // Stack<Integer> st = new Stack<>();
        // ListNode temp = head;
        // while(temp != null){
        //     st.push(temp.val);
        //     temp =temp.next;
        // }
        // temp =head;
        // while(temp != null){
        //     if(st.peek() != temp.val) return false;
        //     temp = temp.next;
        //     st.pop();
        // }
        // return true;
    }
}
