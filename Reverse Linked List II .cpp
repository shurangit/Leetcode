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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* head_new=new ListNode(-1);
        head_new->next=head;
        head=head_new;
        for(int i=0;i<m-1;i++){
            head=head->next;
        }
        ListNode* pre=head->next, *cur=pre->next;
        for(int i=0;i<n-m;i++){
            ListNode* tmp=cur->next;
            cur->next=pre;
            pre=cur;
            cur=tmp;
        }
        head->next->next=cur;
        head->next=pre;
        return head_new->next;
    }
};