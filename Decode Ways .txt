class Solution {
public:
    int numDecodings(string s) {
        if(s.empty()) return 0;
        int n=s.size();
        int n0=1; //index i-1
        int n1=(s[0]=='0')? 0:1;
        if(n==1) return n1;
        for(int i=1;i<n;i++){
            int tmp=n1;
            if(s[i]=='0') n1=0;
            if((s[i-1]=='2'&&s[i]<'7')||s[i-1]=='1') n1+=n0;
            if(n1==0) return 0;
            n0=tmp;
        }
        return n1;
    }
};