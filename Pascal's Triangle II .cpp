class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(1,1);
        for(int i=1;i<=rowIndex;i++){
            res.push_back(1);
            for(int j=res.size()-2;j>0;j--){
                 res[j]+=res[j-1];
            }
          
        }
        return res;
    }
};