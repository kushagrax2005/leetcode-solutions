class Solution {
public:
    void dfs(int i,vector<vector<int>>&v,vector<int>&vis)
    {
        if(vis[i]==2)return;
        vis[i]++;
        for(int j=0;j<v[i].size();j++)
        {
            dfs(v[i][j],v,vis);
        }
    }
    bool canFinish(int numCourses, vector<vector<int>>& p) {
        int m=p.size();
        int i=0;
        int n=numCourses;
        vector<vector<int>>v(n);
        while(i<m)
        {
            v[p[i][0]].push_back(p[i][1]);
            i++;
        }
        i=0;
        vector<int>vv(n,0);
        while(i<p.size())
        {
            vector<int>vis(n,0);
            if(!vv[p[i][0]])
            dfs(p[i][0],v,vis);
            vv[p[i][0]]=1;
            if(vis[p[i][0]]>1)return false;
            i++;
        }
        return true;
    }
};