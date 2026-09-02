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
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        // q.push(k);
        pair<int,int> node={0,k};
        pq.push(node);
        while(!pq.empty())
        {
            node=pq.top();
            pq.pop();
            for(auto it:v[node.second])
            {
                if(dis[it.first]>dis[node.second]+it.second)
                {
                    dis[it.first]=dis[node.second]+it.second;
                    pq.push({dis[it.first],it.first});
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