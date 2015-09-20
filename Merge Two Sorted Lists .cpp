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


//python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        newhead=ListNode(-1)
        cur=newhead
        while l1 and l2:
            if l1.val<l2.val:
                cur.next=l1
                l1=l1.next
                cur=cur.next
            else:
                cur.next=l2
                l2=l2.next
                cur=cur.next
        if l1:
            cur.next=l1
        elif l2:
            cur.next=l2
        return newhead.next
                
        
