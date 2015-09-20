class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> sol;
        helper(res,sol,n,k,1);
        return res;
    }
    void helper(vector<vector<int>>& res, vector<int>& sol,int n, int k, int start){
        if(k==0) res.push_back(sol);
        for(int i=start;i<=n;i++){
            sol.push_back(i);
            helper(res,sol,n,k-1,i+1);
            sol.pop_back();
        }
    }
};