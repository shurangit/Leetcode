class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string res="";
        if(nums.empty()) return res;
        vector<string> nu;
        for(int i=0;i<nums.size();i++){
            nu.push_back(to_string(nums[i]));
        }
        sort(nu.begin(),nu.end(),cmp);
        for(int i=0;i<nu.size();i++){
            res+=nu[i];
        }
        int pos=0;
        while(res[pos]=='0'&&pos<res.size()-1) pos++;
        return res.substr(pos);
    }
    
    static bool cmp(string a, string b){
        return a+b>b+a;
    }
};