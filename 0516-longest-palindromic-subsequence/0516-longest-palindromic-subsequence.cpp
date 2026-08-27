class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        string a=s;
        reverse(a.begin(),a.end());
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(j==0||i==0)
                {
                    dp[i][j]=0;
                    continue;
                }
                if(s[i-1]==a[j-1])
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][n];
    }
};