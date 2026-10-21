class Solution {
public:
    int maxProduct(vector<string>& w) {
        int n=w.size();
        vector<int>mask(n,0);
        for(int i=0;i<n;i++)
        {
            int wo=0;
            for(int j=0;j<w[i].size();j++)
            {
                wo |= (1<<(w[i][j]-'a'));
            }
            mask[i]=wo;
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if((mask[i] & mask[j])==0)
                {
                    ans=max(ans,(int)w[i].size()*(int)w[j].size());
                }
            }
        }
        return ans;
    }
};