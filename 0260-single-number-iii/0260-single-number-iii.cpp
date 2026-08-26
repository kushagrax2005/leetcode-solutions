class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int x=0;
        while(i<n)
        {
            x^=nums[i];
            i++;
        }
        int a=0;
        int b=0;
        int j=1;
        while(true)
        {
            if(j&x)break;
            j=j<<1;
        }
        i=0;
        while(i<n)
        {
            if(j&nums[i])a^=nums[i];
            else b^=nums[i];
            i++;
        }
        return {a,b};
    }
};