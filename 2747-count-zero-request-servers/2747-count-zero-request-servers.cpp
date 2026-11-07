class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& q) {

        for(int i=0;i<logs.size();i++)
            swap(logs[i][0],logs[i][1]);

        sort(logs.begin(),logs.end());

        vector<int> ans(q.size());
        vector<int>freq(n+1,0);
        vector<pair<int,int>>v;

        for(int i=0;i<q.size();i++)
        {
            v.push_back({q[i],i});
        }
        sort(v.begin(),v.end());
        int l=0,r=0,c=0;
        for(int i=0;i<q.size();i++)
        {
            int a=v[i].first-x;
            int b=a+x;
            while(r<logs.size() && logs[r][0]<=b)
            {
                freq[logs[r][1]]++;
                if(freq[logs[r][1]]==1)c++;
                r++;
            }
            while(l<r&&logs[l][0]<a)
            {
                freq[logs[l][1]]--;
                if(freq[logs[l][1]]==0)c--;
                l++;
            }
            ans[v[i].second]=n-c;
        }
        return ans;
    }
};