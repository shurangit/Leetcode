class Solution {
public:

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> sol;
        if(candidates.empty()) return res;
        sort(candidates.begin(),candidates.end());
        helper(candidates,target,res,sol,0);
        return res;
    }
    
    void helper(vector<int>& candidates, int target, vector<vector<int>>& res, vector<int>& sol, int start){
        if(target<0) return;
        if(target==0){
            res.push_back(sol);
            return;
        }
        for(int i=start;i<candidates.size();i++){
            if(i>start&&candidates[i]==candidates[i-1]) continue;
            sol.push_back(candidates[i]);
            helper(candidates,target-candidates[i],res,sol,i+1);
            sol.pop_back();
        }
    }
};