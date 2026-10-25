class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int i=0;
        int m=grid.size();
        int n=grid[0].size();
        vector<int>vis(n*m,0);
        vector<pair<int,int>>vec={{0,1},{1,0},{0,-1},{-1,0}};
        int ans=0;
        for(int i=1;i<m-1;i++)
        {
            for(int j=1;j<n-1;j++)
            {
                bool flag=true;
                bool flag2=false;
                queue<int>q;
                if(grid[i][j]==0&&!vis[i*n+j])
                {
                    flag2=true;
                    q.push(i*n+j);
                    while(!q.empty())
                    {
                        int node=q.front();
                        q.pop();
                        int x=node/n;
                        int y=node%n;
                        for(int k=0;k<4;k++)
                        {
                            int a=x+vec[k].first;
                            int b=y+vec[k].second;
                            if(a>=0 && a<m && b>=0 && b<n && !vis[a*n+b] && !grid[a][b])
                            {
                                if(a==0||a==m-1||b==0||b==n-1)flag=false;
                                q.push(a*n+b);
                                vis[a*n+b]=1;
                            }
                        }
                    }
                }
                if(flag&&flag2)ans++;
            }
        }
        return ans;
    }
};