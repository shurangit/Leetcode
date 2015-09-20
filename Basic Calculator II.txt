class Solution {
public:
    int calculate(string s) {
        int num=0,lastnum=0,res=0,sign=1,op=0,n=s.size(); //op:0 "+-" op1 "*" op2 "/"
        for(int i=0;i<n;i++){
            if(s[i]==' ') continue;
            else if(s[i]>='0'&&s[i]<='9'){
                num=0;
                while(i<n&&s[i]>='0'&&s[i]<='9'){
                    num=num*10+s[i]-'0';
                    i++;
                }
                i--;
                if(op==0) lastnum=num;
                else if(op==1) lastnum*=num;
                else if(op==2) lastnum/=num;
            }
            else if(s[i]=='+'||s[i]=='-'){
                res+=sign*lastnum;
                sign=(s[i]=='-'? -1:1);
                op=0;
            }
            else if(s[i]=='*') op=1;
            else if(s[i]=='/') op=2;
        }
        res+=sign*lastnum;
        return res;
    }
};