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
    private: vector<vector<int>> res;
    vector<int> tmp;
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        dfs(root,sum);
        return res;
    }
    int dfs(TreeNode* root, int sum){
        if(!root) return 0;
        if(!root->left&&!root->right&&root->val==sum){
            tmp.push_back(root->val);
            res.push_back(tmp);
            tmp.pop_back();
        }
        else{
            tmp.push_back(root->val);
            dfs(root->left,sum-root->val);
            dfs(root->right,sum-root->val);
            tmp.pop_back();
        }
        return 0;
    }
};