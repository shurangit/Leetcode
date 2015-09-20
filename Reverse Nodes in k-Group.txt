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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy=new ListNode(0);
        dummy->next=head; //fake head
        head=dummy;
        ListNode* p=head;
        while(p->next&&p->next->next){
            ListNode *prev=p->next, *cur=prev->next;
            int i=0;
            while(cur&&i<k-1){
                ListNode* tmp=cur->next;
                cur->next=prev;
                prev=cur;
                cur=tmp;
                i++;
            }
            if(i==k-1){
                ListNode* tmp=p->next;
                p->next=prev;
                tmp->next=cur;
                p=tmp;
            }
            else{
                cur=prev->next;
                prev->next=NULL;
                while(cur!=p->next){
                    ListNode* tmp=cur->next;
                    cur->next=prev;
                    prev=cur;
                    cur=tmp;
                    
                }
                break;
            }
        }
        return dummy->next;
    }
    
};