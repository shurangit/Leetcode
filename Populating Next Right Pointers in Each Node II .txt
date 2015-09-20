/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root) return;
        TreeLinkNode *cur=root; 
        TreeLinkNode *prev=NULL, *head=NULL;//prev node of cur's next level
        while(cur){
            while(cur){
                if(cur->left){
                    if(prev!=NULL){
                        prev->next=cur->left;
                    }else head=cur->left;
                    prev=cur->left;
                }
                if(cur->right){
                    if(prev!=NULL) prev->next=cur->right;
                    else head=cur->right;
                    prev=cur->right;
                }
                cur=cur->next;
            }
            cur=head;
            prev=NULL;
            head=NULL;
        }
        
    }
};