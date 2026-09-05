class Solution {
public:
    // map<vector<int>,int>m;
    void sos(int i,int t,vector<int>&vis,vector<vector<int>>&vec,vector<int>&c)
    {
        if(t==0)
        {
            // if(!m.count(vis))
            // {m[vis]++;
            vec.push_back(vis);
            return;
        }
        if(i<0||t<0)return;
        if(t-c[i]>=0)
        {
            vis.push_back(c[i]);
            sos(i-1,t-c[i],vis,vec,c);
            vis.pop_back();
        }
        int j=i;
        while(j>=0&&c[j]==c[i])j--;
        sos(j,t,vis,vec,c);
        return ;
    }
    vector<vector<int>> combinationSum2(vector<int>& c, int t) {
        sort(c.begin(),c.end());
        vector<int>vis;
        vector<vector<int>>vec;
        sos(c.size()-1,t,vis,vec,c);
        return vec;
    }
};