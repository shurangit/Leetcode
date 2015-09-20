class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.empty()) return res;
        string nums[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string s;
        combine(digits,res,nums,0,s);
        return res;
    }
    void combine(string &digits, vector<string> &res,string nums[], int i, string s){
        if(i>=digits.size()) {
            res.push_back(s);
            return;
        }
        string tmp=nums[digits[i]-'0'];
        for(int j=0;j<tmp.size();j++){
            combine(digits,res,nums,i+1,s+tmp[j]);
        }
    }
};