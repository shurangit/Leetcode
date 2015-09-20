class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generate(res,"",n,n);
        return res;
    }
    void generate(vector<string> &res,string s,int n1,int n2){
        if(n1==0&&n2==0){
            res.push_back(s);
        }
        else{
           if(n1>0) generate(res,s+'(',n1-1,n2);
           if(n2>n1) generate(res,s+')',n1,n2-1); 
        }
        
    }
};