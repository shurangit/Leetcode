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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        return sort(nums,0,nums.size()-1);
    }
    TreeNode* sort(vector<int>& nums, int start, int end){
        if(start>end) return NULL;
        int mid=(end+start)/2;
        TreeNode *parent=new TreeNode(nums[mid]);
        parent->left=sort(nums,start,mid-1);
        parent->right=sort(nums,mid+1,end);
        return parent;
    }
};