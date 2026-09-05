class Solution {
public:
    // map<vector<int>,int>m;
    void sos(int i,int t,vector<int>&nums,vector<int>&vis,vector<vector<int>>&vec)
    {
        if(t==0)
        {
            vec.push_back(vis);
            return ;
        }
        if(t<0||i<0)return ;
        // if(dp[i][t]!=-1)return dp[i][t];
        // bool take=false;
        if(t-nums[i]>=0)
        {
            vis.push_back(nums[i]);
            sos(i,t-nums[i],nums,vis,vec);
            vis.pop_back();
        }
        sos(i-1,t,nums,vis,vec);
        // return dp[i][t]=take||not_take;
        return ;
    }
    vector<vector<int>> combinationSum(vector<int>& c, int t) {
        int n=c.size();
        vector<int>v=c;
        sort(v.begin(),v.end());
        // for(int i=0;i<n;i++)
        // {
        //     if(c[i]<=t)
        //     {
        //         int a=t/c[i];
        //         while(a--)
        //         {
        //             v.push_back(c[i]);
        //         }
        //     }   
        // }
        
        vector<vector<int>>vec;
        vector<vector<int>>dp(v.size(),vector<int>(t+1,-1));
        vector<int>vis;
        sos(v.size()-1,t,v,vis,vec);
        return vec;
        // return {};
    }
};