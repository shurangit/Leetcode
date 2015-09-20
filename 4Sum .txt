class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> sol;
        if(nums.size()<4) return res;
        sort(nums.begin(),nums.end());
        helper(res,nums,sol,target,0,4);
        return res;
    }
    void helper(vector<vector<int>>& res,vector<int>& nums, vector<int> sol, int target, int start, int count){
        if(count<=0) return;
        if(count==1){
            for(int i=start;i<nums.size();i++){
                if(nums[i]==target){
                    sol.push_back(target);
                    res.push_back(sol);
                    sol.pop_back(); //exists duplicate
                    return;
                }
            }
        }
        if(count==2) {
            twoSum(res,nums,sol,target,start);
            return;
            
        }
        for(int i=start;i<nums.size()-count+1;i++){
            if(i>start&&nums[i]==nums[i-1]) continue;
            sol.push_back(nums[i]);
            helper(res,nums,sol,target-nums[i],i+1,count-1);
            sol.pop_back();
        }
    }
        void twoSum(vector<vector<int>>& res,vector<int>& nums, vector<int> sol, int target, int start){
            int end=nums.size()-1;
            while(start<end){
                int sum=nums[start]+nums[end];
                if(sum==target){
                    sol.push_back(nums[start]);
                    sol.push_back(nums[end]);
                    res.push_back(sol);
                    sol.pop_back();
                    sol.pop_back();
                    start++;end--;
                    while(nums[start]==nums[start-1]) start++;
                    while(nums[end]==nums[end+1]) end--;
                }
                else if(sum<target) start++;
                else end--;
                
            }
        }
    
};