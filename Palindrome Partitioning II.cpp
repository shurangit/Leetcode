class Solution {
public:
    int minCut(string s) {
       int n=s.size();
       if(n<=1) return 0;
       //use isPal to decide whether is pal. isPal[i][j]=>s[i...j] is pal?
       vector<vector<bool>> isPal(n,vector<bool>(n,false));
       for(int i=n-1;i>=0;i--){
           for(int j=i;j<n;j++){
               if((i+1>j-1||isPal[i+1][j-1])&&s[i]==s[j]) isPal[i][j]=true;
           }
       }
       vector<int> dp(n+1,INT_MAX); //dp[i]->in s(0...i-1) no. of min cut  ***dp[i]=dp[j]+1 if s(j...i-1)is pal 0<=j<i
       dp[0]=-1; 
       for(int i=1;i<=n;i++){
           for(int j=i-1;j>=0;j--){
               if(isPal[j][i-1]) dp[i]=min(dp[i],dp[j]+1);
           }
       }
       return dp[n];
       
    }
    
};