/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
        void sortListHelper(ListNode* head, ListNode* tail) {
        if (head -> next == tail) return;
        /* Partition the list. */
        ListNode* pre = head;
        ListNode* cur = head -> next;
        ListNode* pivot = cur;
        while (cur -> next && cur -> next != tail) {        
            if (pivot -> val > cur -> next -> val) {
                ListNode* temp = pre -> next;
                pre -> next = cur -> next;
                cur -> next = cur -> next -> next;
                pre -> next -> next = temp;
            }
            else cur = cur -> next;
        }
        sortListHelper(head, pivot);
        /* Here is the trick. */
        while (pivot -> next != tail && pivot -> next -> val == pivot -> val)
            pivot = pivot -> next;
        if (pivot -> next != tail) sortListHelper(pivot, tail);
    } 

    ListNode* sortList(ListNode* head) {
        ListNode* new_head = new ListNode(0);
        new_head -> next = head;
        sortListHelper(new_head, NULL);
        return new_head -> next;
    
    }
};