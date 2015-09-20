class Solution {
public:
    bool isHappy(int n) {
        set<long> hash;
        hash.insert(n);
        
        while(1){
            long squ=square(n);
            if(squ==1) return true;
            if(hash.find(squ)!=hash.end()) return false;
            hash.insert(squ);
            n=squ;
        }
        
    }
    long square(int n){
        long sum=0;
        while(n>0){
            int i=n%10;
            sum+=i*i;
            n=n/10;
        }
        return sum;
    }
};