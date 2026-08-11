class Solution {
public:
    int f(int i,vector<int>&dp)
    {
        if(i==0)return 0;
        if(i==1)return 1;
        if(dp[i]!=-1)return dp[i];
        int a=i&1;
        return a+f(i>>1,dp);
    }
    vector<int> countBits(int n) {
        // int i=0;
        // vector<int>v;
        // while(n>=0)
        // {
        //     int a=n;
        //     int b=0;
        //     while(a)
        //     {
        //         if(a&1)b++;
        //         a=a>>1;
        //     }
        //     v.push_back(b);
        //     n--;
        // }
        // reverse(v.begin(),v.end());
        // return v;
        vector<int>dp(n+1,-1);
        vector<int>v(n+1);
        for(int i=0;i<=n;i++)
        {
            v[i]=f(i,dp);
        }
        return v;
    }
};