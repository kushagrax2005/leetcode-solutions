class Solution {
public:
    int networkDelayTime(vector<vector<int>>& f, int n, int k) {
        vector<vector<pair<int,int>>>v(n+1);
        for(int i=0;i<f.size();i++)
        {
            v[f[i][0]].push_back({f[i][1],f[i][2]});
        }
        vector<int>dis(n+1,INT_MAX);
        dis[k]=0;
        queue<int>q;
        q.push(k);
        int node=k;
        while(!q.empty())
        {
            node=q.front();
            q.pop();
            for(auto it:v[node])
            {
                if(dis[it.first]>dis[node]+it.second)
                {
                    q.push(it.first);
                    dis[it.first]=dis[node]+it.second;
                }
            }
        }
        int maxi=0;
        for(int i=1;i<=n;i++)
        {
            if(dis[i]==INT_MAX)return -1;
            maxi=max(dis[i],maxi);
        }
        return maxi;
    }
};