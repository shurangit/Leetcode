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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        while(root||!st.empty()){
            if(root){
                st.push(root);
                root=root->left;
            }
            else{
                root=st.top(); //smallest
                st.pop();
                if(--k==0) return root->val;
                root=root->right; //can't find in left sub, from right sub
            }
        }
    }
};