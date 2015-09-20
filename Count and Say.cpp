class Solution {
public:
    string countAndSay(int n) {
        string res="1";
        if(n==0) return NULL;
        if(n==1) return res;
        
        int count=1;
        int nth=1;
        if(n>=2){
            res="11";
            nth=2;
        }
        while(nth<n){
           string tmp;
           for(int i=0;i<res.length();i++){
               if(res[i]!=res[i+1]){
                   tmp+=to_string(count)+res[i];
                   count=1;
               }else{
                   count++;
               }
           }
           res=tmp;
           nth++;
        }
        return res;
        
    }
};