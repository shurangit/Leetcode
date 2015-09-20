class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        vector<string> result;
        if(wordDict.empty()) return result;
        for(int i=s.size()-1;i>=0;i--){
            if(wordDict.find(s.substr(i))!=wordDict.end()){
                break;
            }
            if(i==0) return result;
        }
        string res="";
        dfs(s,wordDict,res,result);
        return result;
        
    }
    
    void dfs(string s, unordered_set<string>& wordDict, string res, vector<string>& result){
        if(s.size()==0){
            res.erase(res.end()-1);
            result.push_back(res);
            return;
        }
        for(int i=0;i<s.size();i++){
            string tmp=s.substr(0,i+1);
            if(wordDict.find(tmp)!=wordDict.end()){
                string new_s=s.substr(i+1);
                dfs(new_s,wordDict, res+tmp+" ", result);
            }
        }
    }
};