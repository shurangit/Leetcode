class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int m=triangle.size();
        int sum[m];
        for(int i=0;i<m;i++) sum[i]=triangle[m-1][i];
        for(int i=m-2;i>=0;i--){
            for(int j=0;j<i+1;j++){
                sum[j]=(sum[j]>sum[j+1]? sum[j+1]:sum[j])+triangle[i][j];
            }
        }
        return sum[0];
    }
};