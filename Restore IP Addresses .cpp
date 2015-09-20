class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if(s.empty()) return res;
        string tmp="";
        storeIp(s,tmp,res,4);
    }
    void storeIp(string s,string tmp, vector<string> &res, int k){
        if(k==0) {
            if(s.empty()){
                res.push_back(tmp);
            }
            return;
        }else{
            for(int i=1;i<4;i++){
                if(s.size()>=i&&isValid(s.substr(0,i))){
                    if(k==1){
                        storeIp(s.substr(i),tmp+s.substr(0,i),res,k-1);
                    }
                    else{
                        storeIp(s.substr(i),tmp+s.substr(0,i)+'.',res,k-1);
                    }
                }
            }
        }
    }
    bool isValid(string s1){
        if(s1.empty()||s1.size()>3) return false;
        if(s1[0]=='0'&&s1.size()!=1) return false;
        if(s1.size()==3&&stoi(s1)>255) return false;
        return true;
    }
};