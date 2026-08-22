class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int>vis(m*n,0);
        queue<int>q;
        vector<pair<int,int>>v={{-1,0},{0,-1},{0,1},{1,0}};
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(vis[i*n+j] || grid[i][j]=='0') continue;
                q.push(i*n+j);
                vis[i*n+j]=1;
                ans++;
                while(!q.empty())
                {
                    int node=q.front();
                    q.pop();
                    int x=node/n;
                    int y=node%n;
                    for(int jj=0;jj<4;jj++)
                    {
                        int aa=x+v[jj].first;
                        int bb=y+v[jj].second;
                        if(aa>=0 && aa<m && bb>=0 && bb<n && grid[aa][bb]=='1' && !vis[aa*n+bb])
                        {
                            q.push(aa*n+bb);
                            vis[aa*n+bb]=1;
                        }
                    }
                }
            }
        }
        return ans;
    }
};