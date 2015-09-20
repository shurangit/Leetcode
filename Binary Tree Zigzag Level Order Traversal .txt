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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode *> visited;
        visited.push(root);
        while(!visited.empty()){
            int size=visited.size();
            vector<int> level;
            while(size>0){
                
                TreeNode* tmp=visited.front();
                visited.pop();
                level.push_back(tmp->val);
                if(tmp->left) visited.push(tmp->left);
                if(tmp->right) visited.push(tmp->right);
                size--;
            }
            res.push_back(level);
        }
        for(int i=0;i<res.size();i++){
            if(i%2==1){
                reverse(res[i].begin(),res[i].end());
            }
        }
        return res;
        
    }
    
};