class Solution {
public:
    int countElements(vector<int>& nums) {
        int mini=INT_MAX;
        int maxi=INT_MIN;
        int a=0;
        int b=0;
        int n=nums.size();
        for(int x:nums)
        {
            if(x<mini){mini=x;a=0;}
            if(x>maxi){maxi=x;b=0;}
            if(maxi==x)b++;
            if(mini==x)a++;
        }
        if(maxi==mini)return 0;
        return n-a-b;
    }
};