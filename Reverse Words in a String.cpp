class Solution {
public:
    void reverseWords(string &s) {
        int start=0;
        while(start<s.size()&&s[start]==' ') start++; 
        s=s.substr(start,s.size()-start);//remove the start space
        int len=0;
        string res="";
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]!=' ') len++;
            if(s[i]==' '&&len!=0){
                res+=s.substr(i+1,len);
                res+=" ";
                len=0;
            }
        }
        res+=s.substr(0,len);
        s=res;
    }
};