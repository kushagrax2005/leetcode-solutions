class Solution {
public:
    void dfs(int i,vector<vector<int>>&is,vector<int>&vis)
    {
        int node=i;
        vis[i]=1;
        for(int j=0;j<is[node].size();j++)
        {
            if(is[node][j]==1&&!vis[j])dfs(j,is,vis);
        }
    }
    int findCircleNum(vector<vector<int>>& is) {
        int n=is.size();
        vector<int>vis(n,0);
        int c=0;
        // for(int i=0;i<n;i++)
        // {
        //     if(!vis[i])
        //     {
        //         c++;
        //         dfs(i,is,vis);
        //     }    
        // }
        // return c;
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(vis[i])continue;
            q.push(i);
            c++;
            while(!q.empty())
            {
                int node=q.front();
                q.pop();
                if(vis[node])continue;
                vis[node]=1;
                for(int j=0;j<is[node].size();j++)
                {
                    if(is[node][j]==1&&!vis[j])q.push(j);
                }
            }
        }
        return c;
    }
};