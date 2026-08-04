class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>v;
        int i=1;
        while(i<nums.size())
        {
            if(nums[i]-1!=nums[i-1])
            {
                for(int j=nums[i-1]+1;j<nums[i];j++)
                v.push_back(j);
            }
            i++;
        }
        return v;
    }
};