class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=1) return 0;
        int res=0;
        for(int i=1;i<prices.size();i++){
            res+=(prices[i]>prices[i-1]?prices[i]-prices[i-1]:0);
        }
        return res;
    }
};