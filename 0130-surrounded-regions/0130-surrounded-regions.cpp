class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>& b)
    {
        if(i<0||i>=b.size()||j<0||j>=b[0].size())return;
        // if(b[i][j]=='O')mm[i*b[0].size()+j]++;
        if(b[i][j]=='O')b[i][j]='0';
        else return;
        vector<pair<int,int>>v={{0,1},{0,-1},{1,0},{-1,0}};
        for(int k=0;k<4;k++)
        {
            dfs(i+v[k].first,j+v[k].second,b);
        }
    }
    void solve(vector<vector<char>>& b) {
         int m=b.size();
         int n=b[0].size();
        //  unordered_map<int,int>mm;
         for(int j=0;j<n;j++)
         {
            if(b[0][j]=='O')
            {
                dfs(0,j,b);
            }
            if(b[m-1][j]=='O')
            {
                dfs(m-1,j,b);
            }
         }
         for(int i=1;i<m-1;i++)
         {
            if(b[i][0]=='O')
            {
                dfs(i,0,b);
            }
            if(b[i][n-1]=='O')
            {
                dfs(i,n-1,b);
            }
         }
         for(int i=0;i<m;i++)
         {
            for(int j=0;j<n;j++)
            {
                if(b[i][j]=='O')b[i][j]='X';
                else if(b[i][j]=='0')b[i][j]='O';
            }
         }
         return ;
    }
};