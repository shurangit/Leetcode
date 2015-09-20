class Solution {
public:
    int calculate(string s) {
        int res=0, sign=1,nums=0;
        stack<int> signs;
        signs.push(1);
        for(auto c:s){
            if(c>='0'&&c<='9'){
                nums=nums*10+c-'0';
            }
            else if(c=='+'||c=='-'){
                res=res+signs.top()*sign*nums;
                nums=0;
                sign=(c=='-'?-1:1);
            }
            else if(c=='('){
                signs.push(sign*signs.top());
                sign=1;
            }
            else if(c==')'){
                res=res+signs.top()*sign*nums;
                signs.pop();
                nums=0;
                sign=1;
            }
        }
        if(nums) res=res+signs.top()*sign*nums;
        
        return res;
    }
};