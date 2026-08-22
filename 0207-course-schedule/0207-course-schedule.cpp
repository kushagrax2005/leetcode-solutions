class Solution {
public:
    // bool dfs(int i,vector<vector<int>>&v,vector<int>&vis)
    // {
    //     vis[i]=1;
    //     for(auto it:v[i])
    //     {
    //         if(!vis[it]){
    //         if(dfs(it,v,vis)==true)return true;}
    //         else 
    //         {
    //             return true;
    //         }
    //     }
    //     return false;
    // }

    bool dfs(int i, vector<vector<int>>& v, vector<int>& vis)
    {
        if(vis[i] == 1)
            return true;   

        if(vis[i] == 2)
            return false;

        vis[i] = 1;

        for(auto it : v[i])
        {
            if(dfs(it, v, vis))
                return true;
        }
        vis[i] = 2;

        return false;
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
        
        // vector<int>vv(n,0);
        // while(i<p.size())
        // {
        //     vector<int>vis(n,0);
        //     if(!vv[p[i][0]])
        //     dfs(p[i][0],v,vis);
        //     vv[p[i][0]]=1;
        //     if(vis[p[i][0]]>1)return false;
        //     i++;
        // }
        // return true;

        bool ans;
        vector<int>vis(n,0);
        i=0;
        while(i<n)
        {
            if(!vis[i]&&!v[i].empty())
            {
                if(dfs(i,v,vis))return false;
            }
            i++;
        }
        return true;
    }
};