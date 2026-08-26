class Solution {
public:
    bool dfs(int i,vector<vector<int>>&v,vector<int>&vis,vector<int>&vv)
    {
        if(vis[i]==1)return true;
        if(vis[i]==2)return false;
        vis[i]=1;
        for(int it:v[i])
        {
            if(dfs(it,v,vis,vv)==true)return true;
        }
        vv.push_back(i);
        vis[i]=2;
        return false;
    }
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        vector<vector<int>>v(n);
        vector<int>vv;
        vector<int>vis(n,0);
        for(int i=0;i<p.size();i++)
        {
            v[p[i][0]].push_back(p[i][1]);
        }
        bool ans=false;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                ans=ans||dfs(i,v,vis,vv);
                if(ans)return {};
            }
        }
        return vv;
    }
};