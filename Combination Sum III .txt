class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> sol;
        if(k<=0||n<=0) return res;
        helper(res,sol,k,n,1);
        return res;
    }
    void helper(vector<vector<int>>& res,vector<int>sol, int k,int n, int start){
        if(k==1) {
            if(start<=n&&n<=9) 
            {   sol.push_back(n);
                res.push_back(sol);
            return;}
        }
        for(int i=start;i<=9;i++){
            if(i<n){
                sol.push_back(i);
               helper(res,sol,k-1,n-i,i+1);
               sol.pop_back();
            }else{
                break;
            }
            
        }
    }
};