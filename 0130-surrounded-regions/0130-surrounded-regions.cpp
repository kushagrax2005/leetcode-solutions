class Solution {
public:
    void dfs(int i,int j,unordered_map<int,int>&mm,vector<vector<char>>& b)
    {
        if(i<0||i>=b.size()||j<0||j>=b[0].size()||mm.count(i*b[0].size()+j))return;
        if(b[i][j]=='O')mm[i*b[0].size()+j]++;
        else return;
        vector<pair<int,int>>v={{0,1},{0,-1},{1,0},{-1,0}};
        for(int k=0;k<4;k++)
        {
            dfs(i+v[k].first,j+v[k].second,mm,b);
        }
    }
    void solve(vector<vector<char>>& b) {
         int m=b.size();
         int n=b[0].size();
         unordered_map<int,int>mm;
         for(int j=0;j<n;j++)
         {
            if(!mm.count(0*n+j))
            {
                dfs(0,j,mm,b);
            }
            if(!mm.count((m-1)*n+j))
            {
                dfs(m-1,j,mm,b);
            }
         }
         for(int i=1;i<m-1;i++)
         {
            if(!mm.count(i*n+0))
            {
                dfs(i,0,mm,b);
            }
            if(!mm.count(i*n+n-1))
            {
                dfs(i,n-1,mm,b);
            }
         }
         for(int i=0;i<m;i++)
         {
            for(int j=0;j<n;j++)
            {
                if(b[i][j]=='O'&&!mm.count(i*n+j))b[i][j]='X';
            }
         }
         return ;
    }
};