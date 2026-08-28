class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        queue<int>q;
        vector<pair<int,int>>v={{-1,0},{1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};
        // vector<pair<int,int>>v={{1,1},{1,0},{0,1}};
        vector<int>vis(n*n,0);
        if(grid[0][0] || grid[n-1][n-1])
            return -1;
        int node=0;
        q.push(node);
        vis[node]=1;
        int ans=1;
        while(!q.empty())
        {
            int sq=q.size();
            while(sq--)
            {
                node=q.front();
                q.pop();
                if(node == n*n-1)
                return ans;
                for(int i=0;i<8;i++)
                {
                    int x=node/n+v[i].first;
                    int y=node%n+v[i].second;
                    if(x>=0&&x<n&&y>=0&&y<n&&!grid[x][y]&&!vis[x*n+y])
                    {
                        q.push(x*n+y);
                        vis[x*n+y]=1;
                    }
                }
            }
            ans++;
        }
        // if(!vis[n*n-1])return -1;
        return -1;
    }
};