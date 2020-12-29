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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL) {
            return head;
        }
        
        ListNode *list = head, *temp;
        
        while (n > 0) {
            list = list->next;
            n--;
        }
        
        if (list == NULL) {
            return head->next;
        }
        
        temp = head;
        
        while (list->next != NULL) {
            temp = temp->next;
            list = list->next;
        }
        
        temp->next = temp->next->next;
        
        return head;
    }
};
