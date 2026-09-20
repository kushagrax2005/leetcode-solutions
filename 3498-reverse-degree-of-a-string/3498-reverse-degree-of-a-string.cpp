class Solution {
public:
    int reverseDegree(string s) {
        int i=0;
        int n=s.size();
        int ans=0;
        while(i<n)
        {
            ans+=abs(s[i]-97-26)*(i+1);
            i++;
        }
        return ans;
    }
};