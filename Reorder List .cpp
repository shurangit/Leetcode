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
    void reorderList(ListNode* head) {
        if((!head)||(!head->next)) return;
        ListNode *p1=head;
        ListNode *p2=head->next;
        //let p1 point the mid Node 
        while(p2&&p2->next){
            p1=p1->next;
            p2=(p2->next)->next;
        }
        //reverse the last half
        p2=p1->next; //p2 is the head Node
        p1->next=NULL;
        ListNode* head_m=NULL, *tmp;
        while(p2){
            tmp=p2->next;
            p2->next=head_m;
            head_m=p2;
            p2=tmp;
        }
        p1=head;
        p2=head_m;
        while(p2){
            head_m=p1->next;
            p1=p1->next=p2;
            p2=head_m;
        }
        return;
        
    }
};