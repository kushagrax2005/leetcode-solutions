class Solution {
public:
    void f(vector<int>&vis,vector<int>&d,vector<int>&nums,vector<vector<int>>&vec)
    {
        if(d.size()==nums.size())
        {
            vec.push_back(d);
            return;
        }
        for(int j=0;j<nums.size();j++)
        {
            if(vis[j])continue;
            d.push_back(nums[j]);
            vis[j]=1;
            f(vis,d,nums,vec);
            d.pop_back();
            vis[j]=0;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>vec;
        vector<int>vis(nums.size(),0);
        vector<int>d;
        f(vis,d,nums,vec);
        return vec;
    }
};