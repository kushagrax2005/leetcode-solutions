class Solution {
public:
    int missingInteger(vector<int>& nums) {
        unordered_map<int,int>m;
        int i=0;
        int n=nums.size();
        while(i<n)
        {
            m[nums[i]]++;
            i++;
        }
        i=0;
        int sum=0;
        int maxi_sum=0;
        while(i<n-1)
        {
            if(nums[i]+1==nums[i+1])
            {
                sum+=nums[i];
            }
            else break;
            i++;
        }
        sum+=nums[i];
        i=0;
        while(true)
        {
            if(!m.count(sum))return sum;
            sum++;
        }
        return 0;
    }
};