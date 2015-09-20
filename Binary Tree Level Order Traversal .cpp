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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode*> store;
        store.push(root);
        while(!store.empty()){
            int size=store.size();
            vector<int> level;
            while(size>0){
               TreeNode* tmp=store.front();
               store.pop(); 
               level.push_back(tmp->val);
               size--;
               if(tmp->left) store.push(tmp->left);
               if(tmp->right) store.push(tmp->right);
            }
            res.push_back(level);
            
        }
        return res;
        
    }
};