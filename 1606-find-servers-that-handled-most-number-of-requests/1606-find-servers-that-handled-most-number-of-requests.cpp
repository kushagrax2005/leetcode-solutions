class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& a, vector<int>& l) {
        vector<int>v(k,1);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int n=a.size();
        unordered_map<int,int>m;
        set<int>s;
        for(int i=0;i<k;i++)
        {
            s.insert(i);
        }
        int j=0;
        int i=a[j]; 
        int c=0;
        while(j<n || !pq.empty())
        {
            while(!pq.empty() && pq.top().first<=i)
            {
                pair aa=pq.top();
                pq.pop();
                s.insert(aa.second);
                m[aa.second]++;
            }
            if(j<n && i==a[j]&&!s.empty())
            {
                // if(c==k)break;
                int b=j%k;
                // while(!v[b%k])b++;
                auto it=s.lower_bound(b);
                if(it==s.end())it=s.begin();
                pq.push({a[j]+l[j],*it});
                s.erase(it);
            }
            j++;
            if(j>=n && !pq.empty())i=pq.top().first;
            else if(j<n)
            i=a[j];
        }
        vector<int>ans;
        int maxi=0;
        for(auto x:m)
        {
            if(x.second > maxi)
            {
                maxi=x.second;
                ans.clear();
                ans.push_back(x.first);
            }
            else if (x.second==maxi)ans.push_back(x.first);
        }
        return ans;
    }
};