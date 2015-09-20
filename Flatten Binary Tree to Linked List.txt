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
    void flatten(TreeNode *root) {
    if(!root)return;
    stack<TreeNode *> stk;


    while(1){
        if(root->right)stk.push(root->right);

        if(root->left){
            root->right=root->left;
            root->left=NULL;
            root=root->right;
        }
        else{
            if(!stk.size())return;
            root->right=stk.top();
            stk.pop();
            root=root->right;

        }
    }
    }   
    
};