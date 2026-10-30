class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& e, string label, int k) {
     vector<vector<pair<int,int>>>v(n);
     for(int i=0;i<e.size();i++)
     {
        v[e[i][0]].push_back({e[i][1],e[i][2]});
     }   
     vector<vector<int>>dist(n,vector<int>(k+1,1e9));
     vector<int>node={0,0,1};//
     dist[0][1]=0;
     priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
     pq.push(node);
     while(!pq.empty())
     {
        node=pq.top();
        pq.pop();
        for(auto it:v[node[1]])
        {
            int c=node[2];
            if(label[it.first]==label[node[1]])c++;
            else c=1;
            if(c<=k && dist[node[1]][node[2]]+it.second<dist[it.first][c])
            {
                dist[it.first][c]=dist[node[1]][node[2]]+it.second;
                pq.push({dist[node[1]][node[2]]+it.second,it.first,c});
            }
        }
     }
     int ans=1e9;
     for(int j=0;j<=k;j++)ans=min(ans,dist[n-1][j]);
     if(ans==1e9)return -1;
     return ans;
    }
};