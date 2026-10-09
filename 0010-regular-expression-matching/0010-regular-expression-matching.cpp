
class Solution {
public:
    bool f(int i,int j,string &s,string &p,vector<vector<int>>&dp)
    {
        if(i==s.size())
        {
            while(j<p.size())
            {
                if(j+1>=p.size() || p[j+1]!='*')
                    return false;
                j+=2;
            }
            return true;
        }

        if(j==p.size()) return false;

        if(dp[i][j]!=-1) return dp[i][j];

        if(j+1<p.size() && p[j+1]=='*')
        {
            return dp[i][j] =
                f(i,j+2,s,p,dp) ||
                ((s[i]==p[j] || p[j]=='.') &&
                 f(i+1,j,s,p,dp));
        }

        if(s[i]==p[j] || p[j]=='.')
        {
            return dp[i][j]=f(i+1,j+1,s,p,dp);
        }

        return dp[i][j]=false;
    }

    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();

        vector<vector<int>>dp(n,vector<int>(m,-1));

        return f(0,0,s,p,dp);
    }
};
