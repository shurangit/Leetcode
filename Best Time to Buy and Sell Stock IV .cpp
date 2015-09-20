class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.empty()||k==0) return 0;
        //too many transaction times
        int len=prices.size();
        if(len<=k){
            return helper(prices);
        }
        vector<vector<int>> global(len,vector<int>(k+1,0));
        vector<vector<int>> local(len,vector<int>(k+1,0));
        for(int i=1;i<len;i++){
            int diff=prices[i]-prices[i-1];
            for(int j=1;j<=k;j++){
                local[i][j]=max(global[i-1][j-1]+max(diff,0),local[i-1][j]+diff);
                global[i][j]=max(local[i][j],global[i-1][j]);
            }
        }
        return global[len-1][k];
    }
    
    int helper(vector<int>& prices){
        int sum=0;
        //buy i, sell i+1
        for(int i=0;i<prices.size()-1;i++){
            sum=max(sum,sum+prices[i+1]-prices[i]);
        }
        return sum;
    }
};