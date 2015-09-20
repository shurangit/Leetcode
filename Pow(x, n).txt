class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1;
        if(n<0) {
            x=1/x;
            n=-n;
        }
        double res=myPow(x,n/2);
        return (n&1? res*res*x:res*res);
    }
};