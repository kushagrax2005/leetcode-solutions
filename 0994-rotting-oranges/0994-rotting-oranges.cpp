class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int>vis(10*10,0);
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({10*i+j,0});
                    vis[10*i+j]=1;
                }
            }
        }
        int maxi=0;
        vector<pair<int,int>>v={{-1,0},{0,-1},{1,0},{0,1}};
        while(!q.empty())
        {
            pair<int,int>p=q.front();
            q.pop();
            int i=p.first/10;
            int j=p.first%10;
            for(int a=0;a<4;a++)
            {
                int x=i+v[a].first;
                int y=j+v[a].second;
                if(x>=0&&y>=0&&x<m&&y<n&&grid[x][y]==1&&!vis[x*10+y])
                {
                    q.push({x*10+y,p.second+1});
                    vis[x*10+y]=1;
                    maxi=max(maxi,p.second+1);
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(vis[i*10+j]==0&&(grid[i][j]==1||grid[i][j]==2))return -1;
            }
        }
        return maxi;
    }
};