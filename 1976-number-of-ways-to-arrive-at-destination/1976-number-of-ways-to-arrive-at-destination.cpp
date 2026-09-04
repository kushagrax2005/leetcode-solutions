class Solution {
public:
    long long mod=1e9+7;
    int countPaths(int n, vector<vector<int>>& r) {
        long long ans=0;
        vector<vector<pair<long,long>>>v(n);
        for(int i=0;i<r.size();i++)
        {
            v[r[i][0]].push_back({r[i][1],r[i][2]});
            v[r[i][1]].push_back({r[i][0],r[i][2]});
        }
        priority_queue<pair<long,long>,vector<pair<long,long>>,greater<pair<long,long>>>pq;
        pair<long,long>node={0,0};
        pq.push(node);
        vector<long long>dis(n,LLONG_MAX);
        dis[0]=0;
        vector<long long> ways(n, 0);
        ways[0] = 1;
        while(!pq.empty())
        {
            node=pq.top();
            pq.pop();
            for(auto it:v[node.second])
            {
                if(dis[it.first] > node.first + it.second)
                {
                    dis[it.first] = node.first + it.second;
                    ways[it.first] = ways[node.second];

                    pq.push({dis[it.first], it.first});
                }
                else if(dis[it.first] == node.first + it.second)
                {
                    ways[it.first] = (ways[it.first] + ways[node.second]) % mod;
                }
            }
        }
        return ways[n-1];
    }
};