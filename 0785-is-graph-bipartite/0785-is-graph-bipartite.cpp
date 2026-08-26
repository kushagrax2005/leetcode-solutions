class Solution {
public:
    bool isBipartite(vector<vector<int>>& g) {
        int m=g.size();
        vector<int>vis(m,0);
        vis[0]=1;
        for(int i=0;i<m;i++)
        {
            if(!vis[i])continue;
            for(int node:g[i])
            {
                if(!vis[node])
                {
                    vis[node]=vis[i]==1?2:1;
                }
                else if(vis[node]==vis[i])return false;
            }
        }
        for(int i=0;i<m;i++)
        {
            if(!vis[i])vis[i]=1;
            for(int node:g[i])
            {
                if(!vis[node])
                {
                    vis[node]=vis[i]==1?2:1;
                }
                else if(vis[node]==vis[i])return false;
            }
        }
        return true;
    }
};