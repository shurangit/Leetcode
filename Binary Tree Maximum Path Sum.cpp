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
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        int maxSum=INT_MIN;
        int nodeSum1=maxHelper(root,maxSum);
        return maxSum;
    }
    // maxHelper->find max sum of node's subtree, maxSum->total sum of tree
    int maxHelper(TreeNode* node, int &maxSum){
        if(!node) return 0;
      
        int leftV=max(maxHelper(node->left,maxSum),0); //make sure the leftV non-negtive.
        
        int rightV=max(maxHelper(node->right,maxSum),0);
        
        int nodeSum1=0,nodeSum2=0; //sum1->node+max(leftV,rightV); sum2->node+left+right
        nodeSum1=node->val+max(leftV,rightV);
        nodeSum2=node->val+leftV+rightV;
        maxSum=max(maxSum,max(nodeSum1,nodeSum2));
        return nodeSum1;
    }
};