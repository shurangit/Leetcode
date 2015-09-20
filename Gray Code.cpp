class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        if(n<0) return res;
        res.push_back(0);
        int index=1;
        for(int i=1;i<=n;i++){
            for(int j=res.size()-1;j>=0;j--){
                res.push_back(res[j]+index);
            }
            index<<=1;
        }
        return res;
    }
};