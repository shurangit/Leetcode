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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        stack<TreeNode*> st;
        TreeNode* visited=NULL; 
        st.push(root);
        while(!st.empty()){
            TreeNode* tmp=st.top();
            //tmp has no child or tmp's child has visited
            if((tmp->left==NULL&&tmp->right==NULL)||(visited!=NULL&&(tmp->left==visited||tmp->right==visited))){
                res.push_back(tmp->val);
                st.pop();
                visited=tmp;
            }
            else{
                if(tmp->right) st.push(tmp->right);
                if(tmp->left) st.push(tmp->left);
            }
        }
        return res;
    }
};