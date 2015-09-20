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

//python
class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        hash={")":"(","}":"{","]":"["}
        stack=[]
        for i in s:
            if i not in hash:
                stack.append(i)
            else:
                if stack:
                    if stack[-1]==hash[i]:
                        stack.pop()
                    else:
                        return False
                else:
                    return False
        if stack:
            return False
        else:
            return True
