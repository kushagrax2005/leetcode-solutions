class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int i=0;
        int n=nums.size();
        unordered_map<int,int>m;
        while(i<n)
        {
            m[nums[i]]++;
            i++;
        }
        i=1;
        while(i<n+2)
        {
            if(!m.count(k*i))return k*i;
            i++;
        }
        return 0;
    }
};