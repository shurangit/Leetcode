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
    ListNode* swapPairs(ListNode* head) {
        if((!head)||(!head->next)) return head;
        ListNode* res=new ListNode(-1);
        res->next=head;
        ListNode *cur=res, *first=NULL, *second=NULL;
        while((first=cur->next)&&(second=cur->next->next)){
            ListNode *tmp=second->next;
            cur->next=second;
            second->next=first;
            first->next=tmp;
            cur=first;
        }
        return res->next;
    }
};