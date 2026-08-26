class Solution {
public:
    void dfs(int i,int j,vector<int>&vis,vector<vector<char>>&grid)
    {
        int m=grid.size();
        int n=grid[0].size();
        int node=i*n+j;
        if(i<0||i>=m||j<0||j>=n||grid[i][j]=='0') return ;
        if(grid[i][j]=='1' && !vis[node])
        vis[node]=1;
        else return;
        vector<pair<int,int>>v={{0,1},{0,-1},{-1,0},{1,0}};
        for(int k=0;k<4;k++)
        {
            int aa=i+v[k].first;
            int bb=j+v[k].second;
            dfs(aa,bb,vis,grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        vector<int>vis(m*n,0);
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='1'&&!vis[i*n+j])
                {
                    ans++;
                    dfs(i,j,vis,grid);
                }
            }
        }
        return ans;
    }
};