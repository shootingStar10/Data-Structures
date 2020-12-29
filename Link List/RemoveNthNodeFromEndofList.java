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
    public int first = 0;
    public int k = 0;

    public ListNode removeNthFromEnd(ListNode head, int n) {
        if(head.next == null) {
            return null;
        }
        
        ListNode node = head;
        removeNthFromEndUtil(node, n, null);
        
        if(first == 1) {
            return node.next;
        }
        
        return node;
    }
    
    public void removeNthFromEndUtil(ListNode node, int n, ListNode prev) {
        if(node == null) {
            return;
        }
        
        removeNthFromEndUtil(node.next, n, node);
        
        k++;
        
        if(n == k) {
            if(prev == null) {
                first = 1;
                return;
            }
            
            prev.next = node.next;
        }
    }
}