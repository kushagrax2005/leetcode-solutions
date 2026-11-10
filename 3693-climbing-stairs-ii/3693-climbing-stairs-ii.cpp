class Solution {
public:
    int f(int i,int n,const vector<int>&costs,vector<int>&dp)
    {
        if(i==n)return 0;
        if(dp[i]!=-1)return dp[i];
        int a=1e9;
        int b=1e9;
        int cc=1e9;
        if(i+1<=n)a=f(i+1,n,costs,dp)+costs[i]+1;
        if(i+2<=n)b=f(i+2,n,costs,dp)+costs[i+1]+4;
        if(i+3<=n)cc=f(i+3,n,costs,dp)+costs[i+2]+9;
        return dp[i]=min(min(a,b),cc);
    }
    int climbStairs(int n, vector<int>& costs) {
        vector<int>dp(n+1,-1);
        return f(0,n,costs,dp);
    }
};