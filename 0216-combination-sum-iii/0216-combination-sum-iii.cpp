class Solution {
public:
    void f(int i,int k,int n,int &ans,vector<int>&d,vector<vector<int>>&vec)
    {
        if(d.size()==k)
        {
            if(ans==n)vec.push_back(d);
            return ;
        }
        if(ans>n || i>9)return ;
        ans+=i;
        d.push_back(i);
        f(i+1,k,n,ans,d,vec);
        ans-=i;
        d.pop_back(); 
        f(i+1,k,n,ans,d,vec);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        if(n>45)return {};
        // vector<int>nums;
        vector<int>d;
        int ans=0;
        vector<vector<int>>vec;
        // for(int i=1;i<=9;i++)
        // {
        //     nums.push_back(i);
        // }
        f(1,k,n,ans,d,vec);
        return vec;
    }
};