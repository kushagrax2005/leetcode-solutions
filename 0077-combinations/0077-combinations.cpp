class Solution {
public:
    void f(int i,int n,int k,vector<int>&vis,vector<vector<int>>&vec)
    {
        if(vis.size()==k)
        {
            vec.push_back(vis);
            return;
        }
        for(int j=i;j<=n;j++)
        {
            vis.push_back(j);
            f(j+1,n,k,vis,vec);
            vis.pop_back();
        }
        return;
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>vec;
        vector<int>vis;
        f(1,n,k,vis,vec);
        return vec;
    }
};