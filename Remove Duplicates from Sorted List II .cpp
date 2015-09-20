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
        ListNode* head_new=new ListNode(-1);
        head_new->next=head;
        ListNode* pre=head_new, *cur=head;
        while(cur){
            if(cur->next&&cur->val==cur->next->val){
                int val=cur->val;
                while(cur&&cur->val==val){
                    ListNode *tmp=cur->next;
                    pre->next=tmp;
                    delete cur;
                    cur=tmp;
                }
            }
            else{
                pre=cur;
                cur=cur->next;
            }
        }
        return head_new->next;
    }
};