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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int carry = 0;
        ListNode head = null;
        ListNode prev = null;
        
        while(l1 != null && l2 != null) {
            int sum = l1.val+l2.val+carry;
            carry = sum/10;
            sum = sum%10;
            
            if(head == null) {
                head = new ListNode(sum);
                prev = head;
            } else {
                ListNode node = new ListNode(sum);
                prev.next = node;
                prev = node;
            }
            
            l1 = l1.next;
            l2 = l2.next;
        }
        
        while(l1 != null) {
            int sum = l1.val+carry;
            carry = sum/10;
            sum = sum%10;
            
            if(head == null) {
                head = new ListNode(sum);
                prev = head;
            } else {
                ListNode node = new ListNode(sum);
                prev.next = node;
                prev = node;
            }
            
            l1 = l1.next;
        }
        
        while(l2 != null) {
            int sum = l2.val+carry;
            carry = sum/10;
            sum = sum%10;
            
            if(head == null) {
                head = new ListNode(sum);
                prev = head;
            } else {
                ListNode node = new ListNode(sum);
                prev.next = node;
                prev = node;
            }
            
            l2 = l2.next;
        }
        
        if(carry != 0) {
            if(head == null) {
                head = new ListNode(carry);
                prev = head;
            } else {
                ListNode node = new ListNode(carry);
                prev.next = node;
                prev = node;
            }
        }
        
        return head;
    }
}