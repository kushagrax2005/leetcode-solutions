class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int ans=0;
        int i=0;
        int n=nums.size();
        while(i<n)
        {
            if(n%(i+1)==0)ans+=(nums[i]*nums[i]);
            i++;
        }
        return ans;
    }
};