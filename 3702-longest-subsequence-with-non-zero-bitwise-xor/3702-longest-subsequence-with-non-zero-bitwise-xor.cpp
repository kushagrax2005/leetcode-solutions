class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int i=0;
        int n=nums.size();
        int c=0;
        int ans=0;
        int z=0;
        while(i<n)
        {
            if(nums[i]==0)
            {
                z++;
            }
            ans^=nums[i];
            i++;
        }
        if(z==n)
        return 0;
        if(ans>0)return n;
        i=0;
        // while(i<n)
        // {
        //     int a=ans^nums[i];
        //     if(nums[i]!=0)return n-1;
        // }
        return n-1;
    }
};