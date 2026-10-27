class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int i=0;
        int ans=0;
        int n=nums.size();
        bool flag=true;
        while(flag)
        {
            int z=0;
            int o=0;
            i=0;
            flag=false;
            while(i<n)
            {
                int a=nums[i]&1;
                if(a==0)z++;
                else o++;
                nums[i]>>=1;
                if(nums[i]>0)flag=true;
                i++;
            }
            ans+=z*o;
        }
        return ans;
    }
};