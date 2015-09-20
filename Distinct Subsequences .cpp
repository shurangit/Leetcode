class Solution {
public:
    int numDistinct(string s, string t) {
        int m=t.size(), n=s.size();
        //set dp[i][j]=> no. of T[0...i-1] in S[0...j-1]
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=0;i<n+1;i++){
            dp[0][i]=1; //null is substring of all strings
        }
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                if(t[i-1]!=s[j-1]) dp[i][j]=dp[i][j-1];
                else dp[i][j]=dp[i-1][j-1]+dp[i][j-1];
            }
        }
        return dp[m][n];
        
    }
};