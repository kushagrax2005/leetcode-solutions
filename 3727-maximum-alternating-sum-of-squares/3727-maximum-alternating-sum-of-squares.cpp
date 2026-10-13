class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            nums[i]=abs(nums[i]);
        }
        sort(nums.begin(),nums.end());
        int l=0;
        int r=n-1;
        long long score=0;
        while(l<=r)
        {
            if(l==r){score+=nums[r]*nums[r];break;}
            score+=nums[r]*nums[r];
            score-=nums[l]*nums[l];
            l++;
            r--;
        }
        return score;
    }
};