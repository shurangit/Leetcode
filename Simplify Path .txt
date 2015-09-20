class Solution {
public:
    string simplifyPath(string path) {
     //remove double slash
        int i=0,n=path.size();
        while(i<n-1){
            if(path[i]=='/'&&path[i+1]=='/') {path.erase(i,1)};
            else i++;
        }
        //make sure the last char is '/'
        if(path[n-1]!='/') path+="/";
        stack<string> sta;
        string res="";
        int flag=0; //count '/'
        for(int i=0;i<n;i++){
            if(path[i]=='/') flag++;
            if(flag==1) res+=path[i];
            if(flag==2){
                if(res=="/.."&&!sta.empty()) {sta.pop()};
                if(res!="/.."&&res!="/.") {sta.push(res)};
                flag=1;
                res="/";
            }
        }
        if(sta.empty()) return "/";
        string res1="";
        while(!sta.empty()){
           res1=sta.top()+res1;
           sta.pop();
        }
        
        return res1;
    }
};