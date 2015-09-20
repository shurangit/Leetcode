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
    bool isValidBST(TreeNode* root) {
        long min=LONG_MIN, max=LONG_MAX;
        return helper(root,min,max);
        
        
    }
    bool helper(TreeNode* root, long min, long max){
        if(!root) return true;
        if(root->val<=min||root->val>=max) return false;
        if(!helper(root->left,min,root->val)||!helper(root->right,root->val,max)) return false;
        return true;
    }
};