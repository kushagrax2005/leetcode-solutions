class Solution {
public:
    int f(int i,int j,string &s,string &a,vector<vector<int>>&dp)
    {
        if(i==0||j==0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i-1]==a[j-1])dp[i][j]=f(i-1,j-1,s,a,dp)+1;
        else dp[i][j]=max(f(i-1,j,s,a,dp),f(i,j-1,s,a,dp));
        return dp[i][j];
    }
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        string a=s;
        reverse(a.begin(),a.end());
        // vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return f(n,n,s,a,dp);
    }
};