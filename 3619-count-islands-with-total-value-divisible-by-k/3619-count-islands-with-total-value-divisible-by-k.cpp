class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int kk) {
        int i=0;
        int m=grid.size();
        int n=grid[0].size();
        vector<int>vis(n*m,0);
        vector<pair<int,int>>vec={{0,1},{1,0},{0,-1},{-1,0}};
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                queue<int>q;
                if(grid[i][j]&&!vis[i*n+j])
                {
                    // bool flag=true;
                    q.push(i*n+j);
                    vis[i*n+j]=1;
                    long long c=0;
                    while(!q.empty())
                    {
                        int node=q.front();
                        q.pop();
                        int x=node/n;
                        int y=node%n;
                        c+=grid[x][y];
                        // if(x==0||x==m-1||y==0||y==n-1)flag=false;
                        for(int k=0;k<4;k++)
                        {
                            int a=x+vec[k].first;
                            int b=y+vec[k].second;
                            if(a>=0 && a<m && b>=0 && b<n && !vis[a*n+b] && grid[a][b])
                            {
                                q.push(a*n+b);
                                vis[a*n+b]=1;
                            }
                        }
                    }
                    if(c%kk==0)ans++;
                }
            }
        }
        return ans;
    }
};