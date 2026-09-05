class Solution {
public:
    void f(int i,int k,int n,int &ans,vector<int>&d,vector<int>&nums,vector<vector<int>>&vec)
    {
        if(d.size()==k)
        {
            if(ans==n)vec.push_back(d);
            return ;
        }
        if(ans>n || i>=nums.size())return ;
        ans+=nums[i];
        d.push_back(nums[i]);
        f(i+1,k,n,ans,d,nums,vec);
        ans-=nums[i];
        d.pop_back(); 
        f(i+1,k,n,ans,d,nums,vec);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        if(n>45)return {};
        vector<int>nums;
        vector<int>d;
        int ans=0;
        vector<vector<int>>vec;
        for(int i=1;i<=9;i++)
        {
            nums.push_back(i);
        }
        f(0,k,n,ans,d,nums,vec);
        return vec;
    }
};