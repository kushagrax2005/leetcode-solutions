class Solution {
public:
    // int f(int i,int j,string s,string a,vec)
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        string a=s;
        reverse(a.begin(),a.end());
        // vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        vector<int>dp(n+1,0);
        vector<int>prev(n,0);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                // if(j==0||i==0)
                // {
                //     dp[i][j]=0;
                //     continue;
                // }
                if(s[i-1]==a[j-1])
                {
                    dp[j]=prev[j-1]+1;
                }
                else
                {
                    dp[j]=max(prev[j],dp[j-1]);
                }
            }
            prev=dp;
        }
        return dp[n];
    }
};