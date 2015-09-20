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
    ListNode* removeElements(ListNode* head, int val) {
        while(head&&head->val==val) {
            ListNode* tmp=head->next;
            delete head;
            head=tmp;
        }
        ListNode* cur=head;
        ListNode* pre;
        while(head){
            if(head->val==val){
                pre->next=head->next;
                delete head;
                head=pre;
            }
            pre=head;
            head=head->next;
        }
        return cur;
    }
    
};
        
        