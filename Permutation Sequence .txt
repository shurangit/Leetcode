class Solution {
public:
    string getPermutation(int n, int k) {
        string res="";
        vector<int> fac(n+1,1);
        //fac store all n! fac[n] is n! 
        for(int i=1;i<=n;i++){
            fac[i]=fac[i-1]*i;
        }
        //num store all nums, num[n-1]='n';
        vector<char> num(n);
        for(int i=0;i<n;i++){
            num[i]=(i+1)+'0';
        }
        k--;
        for(int i=n;i>0;i--){
            int tmp=k/fac[i-1];
            res+=num[tmp];
            k=k%fac[i-1];
            num.erase(num.begin()+tmp);
        }
        return res;
    }
};