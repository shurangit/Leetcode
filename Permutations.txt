class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> sol;
        
        if(nums.empty()) return res;
        vector<bool> used(nums.size(),false);
        helper(res,sol,used,nums);
        return res;
    }
    void helper(vector<vector<int>>& res, vector<int>& sol, vector<bool>& used, vector<int>& nums){
        if(sol.size()==nums.size()){
            res.push_back(sol);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(used[i])continue;
            else{
                used[i]=true;
                sol.push_back(nums[i]);
                helper(res,sol,used,nums);
                used[i]=false;
                sol.pop_back();
            }
            
            
        }
    }
};