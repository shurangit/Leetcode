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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL) return NULL;
        ListNode* pre=head;
        ListNode* cur=head;
        int count=0;
        
        while(count<n){
            pre=pre->next;
            count++;
        }
        if(!pre) return head->next;
        
        while(pre->next){
            pre=pre->next;
            cur=cur->next;
        }
        ListNode* tmp=cur->next;
        cur->next=tmp->next;
        delete tmp;
        return head;
        
    }
};