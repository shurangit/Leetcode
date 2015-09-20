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
    vector<TreeNode*> generateTrees(int n) {
        return helper(1,n);
    }
    vector<TreeNode*> helper(int start,int end){
        vector<TreeNode*> res;
        if(start>end) res.push_back(0);
        if(start==end) res.push_back(new TreeNode(start));
        else{
            for(int i=start;i<=end;i++){
                vector<TreeNode*> leftl=helper(start,i-1);
                vector<TreeNode*> rightl=helper(i+1,end);
                for(int j=0;j<leftl.size();j++){
                    for(int k=0;k<rightl.size();k++){
                        TreeNode* tmp=new TreeNode(i);
                        tmp->left=leftl[j];
                        tmp->right=rightl[k];
                        res.push_back(tmp);
                    }
                }
            }
            
        }
        return res;
    }
};