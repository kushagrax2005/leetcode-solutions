class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>pre=nums;
        vector<int>suf=nums;
        for(int i=1;i<n;i++)
        {
            int j=n-1-i;
            pre[i]=max(pre[i-1],pre[i]);
            suf[j]=min(suf[j],suf[j+1]);
        }
        for(int i=0;i<n;i++)
        {
            if(pre[i]-suf[i]<=k)return i;
        }
        return -1;
    }
};