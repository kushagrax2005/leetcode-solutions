class Solution {
public:
    vector<int> decode(vector<int>& e, int f) {
        vector<int>v;
        v.push_back(f);
        int a=f;
        int i=0;
        while(i<e.size())
        {
            a=a^e[i];
            v.push_back(a);
            i++;
        }
        return v;
    }
};