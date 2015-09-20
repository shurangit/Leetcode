class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int ss[256]={0}, tt[256]={0};
        if(s.length()==0) return true;
        for(int i=0;i<s.length();i++){
            if(ss[s[i]]>0||tt[t[i]]>0){
                if(ss[s[i]]==tt[t[i]]) continue;
                else return false;
            }
           else{
              ss[s[i]]=i+1;
              tt[t[i]]=i+1;  
           }
            
        }
        return true;
    }
};