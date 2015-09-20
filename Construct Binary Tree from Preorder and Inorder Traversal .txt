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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty()) return NULL;
        TreeNode* root=new TreeNode(preorder[0]);
        helper(root,preorder,inorder,0,(int)preorder.size()-1,0,inorder.size()-1);
        return root;
    }
    void helper(TreeNode* root,vector<int>& preorder, vector<int>& inorder, int ps, int pe,int is, int ie){
        int i=is;
        while(inorder[i]!=root->val) i++;
        if(i>is){
            TreeNode *left=new TreeNode(preorder[ps+1]);
            root->left=left;
            helper(root->left,preorder,inorder,ps+1,ps+i-is,is,i-1);
        }
        if(i<ie){
            TreeNode *right=new TreeNode(preorder[ps+i-is+1]);
            root->right=right;
            helper(root->right,preorder,inorder,ps+i-is+1,pe,i+1,ie);
        }
        
    }
};