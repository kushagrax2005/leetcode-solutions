class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int a=INT_MAX;
        for(int i=0;i<nums1.size();i++)
        {
            if((nums1[i]&1) && a>nums1[i])
            {
                a=nums1[i];
            }
        }
        if(a==INT_MAX)return true;
        for(int i=0;i<nums1.size();i++)
        {
            if(!(nums1[i]&1) && nums1[i]<a)return false;
        }
        return true;
    }
};