class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len=prices.size();
        if(len<=1) return 0;
        int res=0,minn=prices[0],maxx=prices[len-1];
        vector<int> prep(len,0);
        //store the max profit from (0,i)
        for(int i=1;i<len;i++){
            minn=min(minn,prices[i]);
            res=max(res,prices[i]-minn);
            prep[i]=res;
        }
        //calculate the max profit from[i,len-1] + prep[i]
        for(int i=len-1;i>=0;i--){
            maxx=max(maxx,prices[i]);
            res=max(res,maxx-prices[i]+prep[i]);
        }
        return res;
    }
};