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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int la=length(headA);
        int lb=length(headB);
        if(la==0||lb==0) return NULL;
        ListNode *a=headA;
        ListNode *b=headB;
        //make them the same length
        if(la>lb){
            int gap=la-lb;
            for(int i=0;i<gap;i++){
                a=a->next;
            }
        }
        if(la<lb){
            int gap=lb-la;
            for(int i=0;i<gap;i++){
                b=b->next;
            }
        }
        while(a&&b){
            if(a==b) return a;
            else{
                a=a->next;
                b=b->next;
            }
        }
        return NULL;
    }
    int length(ListNode *p){
        int l=0;
        if(!p) return l;
        ListNode *tmp=p;
        while(tmp){
            l++;
            tmp=tmp->next;
        }
        return l;
    }
};