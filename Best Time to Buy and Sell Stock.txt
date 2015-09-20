class Solution { //find the lowest to buy and highest to sell
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=1) return 0;
        int maxp=INT_MIN, minp=INT_MAX;
        for(int i=0;i<prices.size();i++){
            minp=min(minp,prices[i]);
            maxp=max(maxp,prices[i]-minp);
        }
        return maxp;
    }
};