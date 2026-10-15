class Solution {
public:
    int f(vector<int>&v)
    {
        int i=0;
        int n=v.size();
        unordered_map<int,int>m;
        int c=0;
        while(i<n)
        {
            if(!m.count(v[i]))c++;
            m[v[i]]++;
            i++;
        }
        return c*c;
    }
    int sumCounts(vector<int>& nums) {
        int i=0;
        int n=nums.size();
        int j=i;
        int ans=0;
        while(i<n)
        {
            j=i;
            vector<int>v;
            while(j<n)
            {
                v.push_back(nums[j]);
                ans+=f(v);
                j++;
            }
            i++;
        }
        return ans;
    }
};