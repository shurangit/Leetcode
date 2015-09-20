class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> level;
        helper(s,0,res,level);
        return res;
    }
    void helper(string s, int index, vector<vector<string>>& res, vector<string>& level){
        if(index==s.length()) {
            res.push_back(level);
            return;
        }
        for(int i=index;i<s.length();i++){
            int l=index, r=i;
            bool isP=true;
            while(l<r){
                if(s[l++]!=s[r--]){
                    isP=false;
                    break;
                }
            }
            if(isP){
                level.push_back(s.substr(index,i-index+1));
                helper(s,i+1,res,level);
                level.pop_back();
            }
        }
    }
};