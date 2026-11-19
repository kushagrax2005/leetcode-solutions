class Solution {
public:
    int minimizeSum(vector<int>& nums) {
     sort(nums.begin(),nums.end());
     if(nums.size()==3)return 0;
     int n=nums.size();
     int i=0;
     int j=n-1;
     int a=nums[j]-nums[i+2];
     int b=nums[j-2]-nums[i];
     if(nums[j]-nums[i+1]<nums[j-1]-nums[i])i++;
     else j--;
     if(nums[j]-nums[i+1]<nums[j-1]-nums[i])i++;
     else j--;
     return min({nums[j]-nums[i],a,b});
    //  return nums[nums.size()-1]-nums[2];  
    }
};