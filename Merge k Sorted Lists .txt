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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;
        int end=lists.size()-1;
        while(end>0){
            int begin=0;
            while(begin<end){
                lists[begin]=mergeTwoLists(lists[begin],lists[end]);
                begin++;end--;
            }
        }
        return lists[0];
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL&&l2==NULL) return NULL;
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        ListNode* res=new ListNode(-1);
        ListNode* head=res;
        while(l1&&l2){
            if((l1->val<l2->val)){
                head->next=l1;
                head=head->next;
                l1=l1->next;
            }
            else{
               head->next=l2;
               head=head->next;
               l2=l2->next; 
            }
        }
        head->next=l1? l1:l2;
        return res->next;
    }
};