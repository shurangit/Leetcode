class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        
        vector<bool> store(s.size()+1,false); //store[i] find s[0...i]
        store[0]=true;
        for(int i=0;i<s.size();i++){
            for(int k=i;k>=0;k--){
                if(store[k]&&wordDict.find(s.substr(k,i-k+1))!=wordDict.end()) {
                    store[i+1]=true;
                    break;
                }
            }
        }
        return store[s.size()];
    }
};