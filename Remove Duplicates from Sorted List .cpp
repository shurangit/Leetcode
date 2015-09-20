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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head||head->next==NULL) return head;
        ListNode* cur=head;
        while(head&&head->next){
            ListNode* next=head->next;
            if(head->val==next->val){
                head->next=next->next;
                delete next;
            }else{
                head=head->next;
            }
        }
        return cur;
    }
};