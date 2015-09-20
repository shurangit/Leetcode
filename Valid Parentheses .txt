class Solution {
public:
    bool isValid(string s) {
        stack<char> p;
        
        for(int i=0;i<s.length();i++){
            if(s[i]=='('||s[i]=='['||s[i]=='{'){
                p.push(s[i]);
            }else{
                if(p.empty()) return false;
                char tmp=p.top();
                p.pop();
                if((tmp=='('&&s[i]!=')')||(tmp=='['&&s[i]!=']')||(tmp=='{'&&s[i]!='}')) return false;
            }
        }
        return p.empty();
        
    }
};