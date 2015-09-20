class Solution {
public:
    string longestPalindrome(string s) {
       if(s.empty()) return "";
        if(s.length()==1) return s;
        int maxlen=1;
        int start=0;
        for(int i=0;i<s.length();i++){
            int str=i;
            int end=i;
            while(end<s.length()-1&&s[i]==s[end+1]) end++; //same s[i]
            i=end;
            while(str>0&&end<s.length()-1&&s[str-1]==s[end+1]) {
                str--;
                end++;
            }
            if(maxlen<end-str+1) {
                start=str;
                maxlen=end-str+1;
            }
        }
        return s.substr(start,maxlen); 
    }
};