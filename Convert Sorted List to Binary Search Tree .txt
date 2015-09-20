/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return NULL;
        int len=0;
        ListNode* cur=head;
        while(cur){
            len++;
            cur=cur->next;
        }
        return sort(head,0,len-1);
    }
    TreeNode* sort(ListNode *&head, int start, int end){
        if(start>end) return NULL;
        int mid=start+(end-start)/2;
        TreeNode *leftchild=sort(head,start,mid-1);
        TreeNode *parent=new TreeNode(head->val);
        parent->left=leftchild;
        head=head->next;
        parent->right=sort(head,mid+1,end);
        return parent;
        
    }
};