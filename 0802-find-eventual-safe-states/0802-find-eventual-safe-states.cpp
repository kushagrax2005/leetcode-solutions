class Solution {
public:
    bool dfs(int i,vector<int>&vis,vector<vector<int>>&graph)
    {
        if(vis[i]==1)return true;
        if(vis[i]==2)return false;
        vis[i]=1;
        for(int it:graph[i])
        {
        if(dfs(it,vis,graph))return true;
        }
        vis[i]=2;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>vis(n,0);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(i,vis,graph);
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(vis[i]==2)ans.push_back(i);
        }
        return ans;
    }
};