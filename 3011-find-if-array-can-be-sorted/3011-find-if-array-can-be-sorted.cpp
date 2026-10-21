class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int i=0;
        int j=0;
        int n=nums.size();
        vector<int>v=nums;
        sort(v.begin(),v.end());
        while(j<n-1)
        {
            int a=__builtin_popcount(nums[i]);
            int b=__builtin_popcount(nums[j+1]);
            if(a==b)j++;
            else
            {
                sort(nums.begin()+i,nums.begin()+j+1);
                i=j+1;
                j=j+1;
            }   
        }
        sort(nums.begin()+i,nums.begin()+j+1);
            if(nums==v)return true;
            return false;
    }
};