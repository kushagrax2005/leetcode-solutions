class Solution {
public:
    int f(int n)
    {
        int ans=0;
        while(n)
        {
            ans+=n%10;
            n=n/10;
        }
        return ans;
    }
    int minSwaps(vector<int>& nums) {
        vector<pair<pair<int,int>,int>>v;
        int i=0;
        int n=nums.size();
        while(i<n)
        {
            v.push_back({{f(nums[i]),nums[i]},i});
            i++;
        }
        sort(v.begin(),v.end());
        vector<int>vis(n,0);
        queue<int>q;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int node=i;
            if(vis[node])continue;
            vis[node]=1;
            q.push(node);
            while(!q.empty())
            {
                node=q.front();
                q.pop();
                if(!vis[v[node].second] &&node!=v[node].second)
                {
                    q.push(v[node].second);
                    vis[v[node].second]=1;
                    ans++;
                }
            }
        }
            return ans;
    }
    
};