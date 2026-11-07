class Solution {
public:
    vector<int> assignTasks(vector<int>& s, vector<int>& t) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >pq;
        int n=s.size();
        int m=t.size();
        for(int i=0;i<n;i++)
        {
            pq.push({s[i],i});
        }
        vector<int>ans(m,0);
        queue<pair<int,int>>q;
        long long i=0;
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>> >pq2;
        // for(int j=0;j<m;j++)q.push({t[j],j});
        int j=0;
        // while(!q.empty() || !pq2.empty())
        while(true)
        {
            if(j<m)
            {
                q.push({t[j],j});
                j++;
            }
            while(!pq2.empty()&&pq2.top().first<=i)
            {
                pair aa=pq2.top();
                // if(aa.first>i)break;
                pq2.pop();
                pq.push({s[ans[aa.second]],ans[aa.second]});
            }
            while(!q.empty()&&!pq.empty())
            {
                pair a=q.front();
                q.pop();
                pair b=pq.top();
                pq.pop();
                ans[a.second]=b.second;
                pq2.push({i+a.first,a.second});
            }
            if(j==m&&q.empty()&&pq2.empty())break;
            if(j==m && pq.empty()) 
            {
            i = pq2.top().first;
            }
            else
            i++;
        }
        return ans;
    }
};