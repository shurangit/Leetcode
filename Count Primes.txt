class Solution {
public:
    int countPrimes(int n) {
        if(n<=2) return 0;
        bool* p=new bool[n];
        double s=sqrt(n);
        for(int i=2;i<=s;i++){
            if(!p[i]){
                for(int j=i*i;j<n;j+=i){
                    p[j]=true;
                }
            }
        }
        int count=0;
        for(int i=2;i<n;i++){
            if(!p[i]) count++;
        }
        return count;
    }
    
    
};