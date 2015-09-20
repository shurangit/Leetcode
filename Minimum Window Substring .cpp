class Solution {
public:
    string minWindow(string s, string t) {
        string res="";
        if(s.size()==0||t.size()==0) return res;
        map<char, int> hash;
        map<char, int> window;
        for(int i=0;i<t.size();i++){
            hash[t[i]]++;
        }
        int minLen=INT_MAX;
        int lettercount=0;
        for(int slow=0,fast=0;fast<s.size();fast++){
            char c=s[fast];
            if(hash.find(c)!=hash.end()){
                window[c]++;
                if(window[c]<=hash[c]) lettercount++;
            }
            if(lettercount>=t.length()){
                while(hash.find(s[slow])==hash.end()||window[s[slow]]>hash[s[slow]]){
                    window[s[slow]]--;
                    slow++;
                }
                if(fast-slow+1<minLen){
                    minLen=fast-slow+1;
                    res=s.substr(slow,minLen);
                    
                }
                
            }
        }
        return res;
    }
};