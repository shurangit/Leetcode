class Solution {
public:
    bool isPalindrome(string s) {
        if(s.length()==0) return true;
        if(s.length()==1) return true;
        string tmp;
        for(int i=0;i<s.length();i++){
            if(s[i]>='A'&&s[i]<='Z'){
                tmp+=s[i]-'A'+'a';
            }else if((s[i]>='a'&&s[i]<='z')||(s[i]>='0'&&s[i]<='9')){
                tmp+=s[i];
            }else continue;
        }
        int n=tmp.size()-1;
        int i=0, j=n;
        while(i<j){
            if(tmp[i]!=tmp[j]) return false;
            i++;
            j--;
        }
        return true;
        
    }
};