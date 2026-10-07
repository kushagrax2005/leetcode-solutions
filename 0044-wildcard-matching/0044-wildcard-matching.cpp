class Solution {
public:
    bool f(int i,int j,string &s,string &p,vector<vector<int>>&dp)
    {
        if(i==s.size())
        {
            while(j<p.size())
            {
                if(p[j]!='*')return false;
                j++;
            }
            return true;
        }
        if(j==p.size())return false;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i]==p[j] ||p[j]=='?' )
        {
            return dp[i][j]=f(i+1,j+1,s,p,dp);
        }
        else if(s[i]!=p[j]&&p[j]!='*')return dp[i][j]=false;
        return dp[i][j]=f(i,j+1,s,p,dp)||f(i+1,j,s,p,dp);
    }
    bool isMatch(string s, string p) {
        int i=0;
        int n=s.size();
        int m=p.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(0,0,s,p,dp);
    }
};