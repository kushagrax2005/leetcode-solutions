class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int i=0;
        int a=0;
        int b=-1;
        int ans=0;
        int n=nums.size();
        int j=0;
        while(j<n)
        {
        int c=nums[j];
        i=j+1;
        a=1;
        b=-1;
        while(i<n)
        {
            if(b==-1)
            {
                if(c>nums[i])b=0;
                else if(c<nums[i])b=1;
            }
            if(b==0)
            {
                if(c>nums[i])
                {
                    a++;
                    ans=max(ans,a);
                }
                else
                {
                    a=1;
                    b=-1;
                }
                c=nums[i];
            }
            else if(b==1)
            {
                if(c<nums[i])
                {
                    a++;
                    ans=max(ans,a);
                }
                else
                {
                    a=1;
                    b=-1;
                }
                c=nums[i];
            }
            i++;
        }
        j++;
        }
        return ans==0?1:ans;
    }
};