class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& f, int src, int dst, int k) {
        vector<vector<pair<int,int>>>v(n);
        for(int i=0;i<f.size();i++)
        {
            v[f[i][0]].push_back({f[i][1],f[i][2]});
        }
        vector<int>dis(n,INT_MAX);
        dis[src]=0;
        queue<int>q;
        int node=src;
        q.push(node);
        int sq=0;
        int ans=0;
        while(!q.empty())
        {
            sq=q.size();
            vector<int> temp = dis;
            while(sq--)
            {node=q.front();
            q.pop();
            for(auto it:v[node])
            {
                if(temp[it.first]>dis[node]+it.second)
                {
                    temp[it.first]=dis[node]+it.second;
                    q.push(it.first);
                }
            }
            }
            dis=temp;
            if(ans==k)break;
            ans++;
        }
        return dis[dst]==INT_MAX?-1:dis[dst];
    }
};