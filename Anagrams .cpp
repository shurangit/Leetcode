class Solution {
public:
    vector<string> anagrams(vector<string>& strs) {
        vector<string> res;
        unordered_map<string,int> hash;
        if(strs.empty()) return res;
        for(int i=0;i<strs.size();i++){
            string tmp=strs[i];
            sort(tmp.begin(),tmp.end());
            if(hash.find(tmp)==hash.end()){
                hash[tmp]=i;
            }
            else{
                res.push_back(strs[i]);
                if(hash.find(tmp)->second!=-1){
                    res.push_back(strs[hash.find(tmp)->second]);
                    hash.find(tmp)->second=-1;
                }
            }
        }
        return res;
    }
};