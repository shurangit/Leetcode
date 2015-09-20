class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.empty()) return res;
        vector<int> sol;
        vector<bool> used(nums.size(),false);
        sort(nums.begin(),nums.end()); 
        helper(nums,res,sol,used);
        return res;
    }

    void helper(vector<int>& nums, vector<vector<int>>& res, vector<int>&sol, vector<bool> used){
        //sol is a complete permutation
        if(sol.size()==nums.size()) {
            res.push_back(sol);
            return;
        }
        for(int i=0;i<nums.size();i++){
            //used nums[i] before
            if(used[i]) continue;
            //this is the same level of res, thus nums[i]£¡=nums[i-1] and nums[i-1]is not used
            if(i>0&&nums[i]==nums[i-1]&&!used[i-1]) continue;
            used[i]=true;
            sol.push_back(nums[i]);
            helper(nums,res,sol,used);
            used[i]=false;
            sol.pop_back();
        }
        
    }
};