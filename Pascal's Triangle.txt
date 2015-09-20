class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if(numRows==0) return res;
        vector<int> tmp;
        tmp.push_back(1);
        res.push_back(tmp);
        if(numRows==1) return res;
        for(int i=2;i<=numRows;i++){
            vector<int> tmp;
            vector<int> last=res.back();
            tmp.push_back(1);
            int len=last.size();
            for(int j=1;j<len;j++){
                int sum=last[j]+last[j-1];
                tmp.push_back(sum);
            }
            tmp.push_back(1);
            res.push_back(tmp);
        }
        return res;
    }
};