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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.empty()) return NULL;
        int l1=inorder.size()-1, l2=postorder.size()-1;
        TreeNode* root=new TreeNode(postorder[l2]);
        helper(root,inorder,postorder,0,l1,0,l2);
        return root;
    }
    void helper(TreeNode* root,vector<int>& inorder,vector<int>& postorder,int is, int ie, int ps, int pe){
        int i=is;
        while(inorder[i]!=root->val) i++;
        if(i>is){
            TreeNode* left=new TreeNode(postorder[ps+i-is-1]);
            root->left=left;
            
            helper(root->left,inorder,postorder,is,i-1,ps,ps+i-is-1);
        }
        if(i<ie){
            TreeNode* right=new TreeNode(postorder[pe-1]);
            root->right=right;
            helper(root->right,inorder,postorder,i+1,ie,ps+i-is,pe-1);
        }
    }
};