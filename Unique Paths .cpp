class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> sum(m,vector<int>(n));
        sum[0][0]=1;
        for(int i=1;i<m;i++){
            sum[i][0]=1;
        }
        for(int j=1;j<n;j++){
            sum[0][j]=1;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                sum[i][j]=sum[i-1][j]+sum[i][j-1];
            }
        }
        return sum[m-1][n-1];
    }
};

//python
class Solution(object):
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        dp=[[1]*n]*m
        for i in range(1,m):
            for j in range(1,n):
                dp[i][j]=dp[i-1][j]+dp[i][j-1]
        return dp[m-1][n-1]
        
