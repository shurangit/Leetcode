/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head) return NULL;
        unordered_map<RandomListNode*,RandomListNode* > hash;
        RandomListNode *p1=head, *p2=new RandomListNode(p1->label);
        hash[head]=p2;
        while(p1){
            //p1->next
            if(p1->next){
               if(hash.count(p1->next)){//p1->next exists
                p2->next=hash[p1->next];
                   
               } else{
                p2->next=new RandomListNode(p1->next->label);
                hash[p1->next]=p2->next;
               } 
            }
            if(p1->random){
                if(hash.count(p1->random)){//p1->next exists
                p2->random=hash[p1->random];
                   
               } else{
                p2->random=new RandomListNode(p1->random->label);
                hash[p1->random]=p2->random;
               } 
            }
            p1=p1->next;p2=p2->next;
            
        }
        return hash[head];
    }
};