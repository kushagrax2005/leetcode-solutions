class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int i=0;
        if(k==1)
        {
            unordered_map<int,int>m;
            while(i<nums.size())
            {
                m[nums[i]]++;
                i++;
            }
            int maxi=-1;
            for(auto it:m)
            {
                if(it.second==1)
                {
                    maxi=maxi<it.first?it.first:maxi;
                }
            }
            return maxi;
        }
        else if(k==nums.size())
        {
            int maxi=0;
            for(i=0;i<nums.size();i++)
            {
                maxi=max(maxi,nums[i]);
            }
            return maxi;
        }
        int a=0;
        int b=0;
        for(i=0;i<nums.size();i++)
        {
            if(nums[i]==nums[0])a++;
            if(nums[i]==nums[nums.size()-1])b++;
        }
        if(a>1&&b>1)return -1;
        else if(a>1||b>1)return b>1?nums[0]:nums[nums.size()-1];
        return max(nums[0],nums[nums.size()-1]);
    }
};