class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> sol;
        res.push_back(sol);
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            int n=res.size();
            for(int j=0;j<n;j++){
                sol=res[j];
                sol.push_back(nums[i]);
                res.push_back(sol);
            }
        }
        return res;
    }
};