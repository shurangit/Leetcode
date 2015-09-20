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
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        stack<TreeNode* > store;
        store.push(root->left);
        store.push(root->right);
        TreeNode* a,*b;
        while(!store.empty()){
            a=store.top();
            store.pop();
            b=store.top();
            store.pop();
            if(!a&&!b) continue;
            if(!a||!b) return false;
            if(a->val!=b->val) return false;
            
            store.push(a->left);
            store.push(b->right);
            store.push(a->right);
            store.push(b->left);
        }
        return true;
        
    }
};