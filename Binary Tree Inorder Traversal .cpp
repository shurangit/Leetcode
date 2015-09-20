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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> visit;
        TreeNode* cur=root;
        while(cur||!visit.empty()){
            //store all left nodes
            if(cur){
                visit.push(cur);
                cur=cur->left;
            }
            //if left node does not have a right node, return to parent.if yes, from its right node from beginning
            else{
                cur=visit.top();
                visit.pop();
                res.push_back(cur->val);
                cur=cur->right;
            }
        }
        return res;
    }
};