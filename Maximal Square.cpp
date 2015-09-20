class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        if(matrix.empty()||matrix[0].empty()) return 0;
        int col=matrix.size(), row=matrix[0].size();
        int res=0;
        vector<vector<int>> dp(col,vector<int>(row,0)); //dp[m][n]=matrix[m][n](as the right down) largest lenth.
        for(int i=0;i<col;i++){
            for(int j=0;j<row;j++){
                dp[i][j]=matrix[i][j]-'0';
                if(i>0&&j>0&&dp[i][j]==1){
                   dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1; 
                }
                res=max(res,dp[i][j]);
                
            }
        }
        return res*res;
        
    }
};