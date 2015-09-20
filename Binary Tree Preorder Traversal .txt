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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        stack<TreeNode*> store;
        store.push(root);
        while(!store.empty()){
            TreeNode* tmp=store.top();
            store.pop();
            res.push_back(tmp->val);
            if(tmp->right) store.push(tmp->right);
            if(tmp->left) store.push(tmp->left);
        }
        return res;
    } 
};