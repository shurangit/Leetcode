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
    TreeNode *first,*second,*pre;
    void recoverTree(TreeNode* root) {
        helper(root);
        swapNodes(first,second);
    }
    
    void helper(TreeNode* root){
        if(!root) return;
        if(root->left) helper(root->left);
        if(pre&&root->val<pre->val){
            if(!first) first=pre; //first is always the 1st
            second=root;
        }
        pre=root;
        if(root->right) helper(root->right);
    }
    
    void swapNodes(TreeNode* n1, TreeNode* n2){
        int tmp=n1->val;
        n1->val=n2->val;
        n2->val=tmp;
    }
};