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
    ListNode* partition(ListNode* head, int x) {
        if(!head) return head;
        ListNode *newhead=new ListNode(-1);
        newhead->next=head;
        ListNode *small=newhead, *cur=small,*large=NULL, *tmp;
        while(cur->next){
            while(cur->next&&cur->next->val>=x) cur=cur->next;
            large=cur;
            while(cur->next&&cur->next->val<x) cur=cur->next;
            if(small==large) small=cur;
            else{
                tmp=cur->next;
                cur->next=small->next;
                small->next=large->next;
                large->next=tmp;
                small=cur;
                cur=large;
            }
        }
        return newhead->next;
    }
};