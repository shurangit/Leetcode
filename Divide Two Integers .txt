
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(!divisor||(dividend==INT_MIN && divisor==-1)) return INT_MAX;
        int sign=((dividend<0)^(divisor<0))? -1:1;
        long long dvd=labs(dividend);
        long long dvs=labs(divisor);
        int res=0;
        while(dvd>=dvs){
            long long tmp=dvs, mul=1;
            while(dvd>=(tmp<<1)){
                tmp<<=1;
                mul<<=1;
            }
            dvd-=tmp;
            res+=mul;
        }
        return res*sign;
        
    }
};