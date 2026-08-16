class Solution {
public:
    bool stoneGameIX(vector<int>& s) {
        int i=0;
        int t=0;
        int n=s.size();
        // int d=0;
        vector<int>v(3,0);
        while(i<n)
        {
            t+=s[i];
            int a=s[i]%3;
            v[a]++;
            i++;
        }
         if (v[0] % 2 == 0) {
            return v[1] >= 1 && v[2] >= 1;
        }
        return v[1] - v[2] > 2 || v[2] - v[1] > 2;
    }
};