class Solution {
public:
    void dfs(int node,vector<int>&ls,vector<int>&vis,vector<vector<int>>&is)
    {
        vis[node]=1;
        ls.push_back(node);
        for(int i=0;i<vis.size();i++)
        {
            if(i!=node && !vis[i]&&is[node][i])
            {
                dfs(i,ls,vis,is);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& is) {
        // int n=is.size();
        // int maxi=n;
        // vector<int>vis(n,0);
        // for(int i=0;i<n;i++)
        // {
        // if(!vis[i])
        // {
        // vector<int>ls;
        // dfs(i,ls,vis,is);
        // int a=ls.size();
        // maxi=maxi-a+1;
        // }
        // }
        // return maxi;

        int n=is.size();
        // int i=0;
        int maxi=0;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++)
        {
            if(vis[i])continue;
            vector<int>ls;
            queue<int>q;
            q.push(i);
            vis[i]=1;
            while(!q.empty())
            {
                int node=q.front();
                q.pop();
                ls.push_back(node);
                for(int j=0;j<n;j++)
                {
                    if(node!=j&&!vis[j]&&is[node][j])
                    {
                        vis[j]=1;
                        q.push(j);
                    }
                }
            }
            maxi=maxi-ls.size()+1;
        }
        return maxi+n;
    }
};