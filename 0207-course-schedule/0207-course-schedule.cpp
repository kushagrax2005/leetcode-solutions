class Solution {
public:
    bool dfs(int i,vector<vector<int>>&v,vector<int>&vis)
    {
        if(vis[i]==1)return true;
        if(vis[i]==2)return false;
        vis[i]=1;
        // bool ans=true;
        for(int j=0;j<v[i].size();j++)
        {
            if(dfs(v[i][j],v,vis))return true;
        }
        vis[i]=2;
        return false;
    }
    bool canFinish(int num, vector<vector<int>>& p) {
        // int i=0;
        vector<int>vis(num,0);
        vector<vector<int>>v(num);
        for(int i=0;i<p.size();i++)
        {
            v[p[i][0]].push_back(p[i][1]);
        }
        for(int i=0;i<num;i++)
        {
            if(!v[i].empty()&&dfs(v[i][0],v,vis))return false;
        }
        return true;
    }
};