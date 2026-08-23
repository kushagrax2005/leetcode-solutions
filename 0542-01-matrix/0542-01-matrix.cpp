class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        // int i=0;
        int m=mat.size();
        int n=mat[0].size();
        // int j=0;
        queue<int>q,q1;
        int node=0;
        q.push(node);
        q1.push(node);
        vector<pair<int,int>>v={{-1,0},{1,0},{0,-1},{0,1}};
        vector<int>vis(m*n,0);
        vis[node]=1;
        vector<vector<int>> vec=mat;
        while(!q.empty())
        {
            node=q.front();
            q.pop();
            int x=node/n;
            int y=node%n;
            for(int i=0;i<4;i++)
            {
                int a=x+v[i].first;
                int b=y+v[i].second;
                if(a>=0&&a<m&&b>=0&&b<n&&!vis[a*n+b])
                {
                    q.push(a*n+b);
                    q1.push(a*n+b);
                    vis[a*n+b]=1;
                }
            }
        }
        while(!q1.empty())
        {
            node=q1.front();
            q1.pop();
            int x=node/n;
            int y=node%n;
            if(mat[x][y]!=0)
            {
                int a1=x-1;
                int b1=y-1;
                int mini=1e9;
                if(a1>=0)
                mini=min(mini,vec[a1][y]+1);
                if(b1>=0)
                mini=min(mini,vec[x][b1]+1);
                vec[x][y]=mini;
            }
        }

            vis.assign(m*n, 0);
            node=n*m-1;
            q.push(node);
            q1.push(node);
            vis[node]=1;  
            while(!q.empty())
        {
            node=q.front();
            q.pop();
            int x=node/n;
            int y=node%n;
            for(int i=0;i<4;i++)
            {
                int a=x+v[i].first;
                int b=y+v[i].second;
                if(a>=0&&a<m&&b>=0&&b<n&&!vis[a*n+b])
                {
                    q.push(a*n+b);
                    q1.push(a*n+b);
                    vis[a*n+b]=1;
                }
            }
        }
        while(!q1.empty())
        {
            node=q1.front();
            q1.pop();
            int x=node/n;
            int y=node%n;
            if(mat[x][y]!=0)
            {
                int a1=x+1;
                int b1=y+1;
                int mini=vec[x][y];
                if(a1<m)
                mini=min(mini,vec[a1][y]+1);
                if(b1<n)
                mini=min(mini,vec[x][b1]+1);
                vec[x][y]=mini;
            }
        }
        return vec;
        }
};