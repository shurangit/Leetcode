class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> store;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/"){
                int top1=store.top(); store.pop();
                int top2=store.top(); store.pop();
                int res=calculate(tokens[i],top2,top1);
                store.push(res);
            }else{
                istringstream stream(tokens[i]);
                int num;
                stream>>num;
                store.push(num);
            }
        }
        return store.top();
        
    }
    
    int calculate(string oper,int a, int b){
        int res;
        switch(oper[0]){
            case '+': res=a+b;break;
            case '-': res=a-b;break;
            case '*': res=a*b;break;
            case '/': res=a/b;break;
        }
        return res;
    }
   
};