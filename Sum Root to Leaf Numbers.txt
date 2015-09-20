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
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        int res=helper(root,0);
        return res;
    }
    int helper(TreeNode*root, int sum){
        int res=sum*10+root->val;
        if(!root->left&&!root->right) return res;
        if(root->left&&root->right) return helper(root->left,res)+helper(root->right,res);
        else return root->left? helper(root->left,res):helper(root->right,res);
        
    }
};