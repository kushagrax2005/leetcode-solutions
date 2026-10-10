class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int i=0;
        int n=nums1.size();
        // vector<int>v;
        unordered_map<long long,long long>m;
        int maxi=0;
        while(i<n)
        {
            int a=abs(nums1[i]-nums2[i]);
            maxi=max(maxi,a);
            m[a]++;
            i++;
        }
        k1+=k2;
        while(k1!=0&&maxi>0)
        {
            long long a=min(k1,(int)m[maxi]);
            m[maxi]-=a;
            m[maxi-1]+=a;
            k1-=a;
            maxi--;
        }
        long long ans=0;
        for(auto it:m)
        {
            ans+=it.first*it.first*it.second;
        }
        return ans;
    }
}; 