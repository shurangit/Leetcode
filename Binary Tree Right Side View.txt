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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(root==NULL) return res;
        queue<TreeNode*> que;
        int last=1; //root
        que.push(root);
        while(!que.empty()){
            
            while(last>0){
                TreeNode* tmp=que.front();
                que.pop();
                if(tmp->left){
                    que.push(tmp->left);
                }
                if(tmp->right){
                    que.push(tmp->right);
                }
                last--; 
                if(last==0) res.push_back(tmp->val);
            }
            last=que.size();
        }
        return res;
    }
};