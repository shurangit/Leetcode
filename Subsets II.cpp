class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> sol;
        res.push_back(sol);
        sort(nums.begin(),nums.end());
        helper(nums,res,sol,0);
        return res;
    }
    
    void helper(vector<int> & nums, vector<vector<int>>& res,vector<int>&sol, int start ){
        for(int i=start;i<nums.size();i++){
            if(i>start&&nums[i]==nums[i-1]) continue;
            sol.push_back(nums[i]);
            res.push_back(sol);
            helper(nums,res,sol,i+1);
            sol.pop_back();
        }
    }
};