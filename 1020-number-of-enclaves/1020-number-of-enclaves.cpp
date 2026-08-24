class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& b)
    {
        if(i<0||i>=b.size()||j<0||j>=b[0].size())return;
        if(b[i][j]==1)b[i][j]=2;
        else return;
        vector<pair<int,int>>v={{0,1},{0,-1},{1,0},{-1,0}};
        for(int k=0;k<4;k++)
        {
            dfs(i+v[k].first,j+v[k].second,b);
        }
    }
    int numEnclaves(vector<vector<int>>& b) {
        int m=b.size();
         int n=b[0].size();
        //  unordered_map<int,int>mm;
         for(int j=0;j<n;j++)
         {
            dfs(0,j,b);
            dfs(m-1,j,b);
         }
         for(int i=1;i<m-1;i++)
         {
            dfs(i,0,b);
            dfs(i,n-1,b);
         }
         int ans=0;
         for(int i=0;i<m;i++)
         {
            for(int j=0;j<n;j++)
            {
                if(b[i][j]==1)ans++;
            }
         }
         return ans;
    }
};