class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>dp(n,-1);
        int i=0,j=0,k=0;
        dp[0]=1;
        int l=1;
        while(l<n)
        {
            int a=dp[i]*2;
            int b=dp[j]*3;
            int c=dp[k]*5;
            int mini=min({a,b,c});
            dp[l]=mini;
            if(a==mini)i++;
            if(b==mini)j++;
            if(c==mini) k++;
            l++;
        }
        return dp[n-1];
    }
};