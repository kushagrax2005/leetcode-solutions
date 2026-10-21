class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string>v;
        int i=10;
        int n=s.size();
        if(n<=10)return {};
        string a=s.substr(0,10);
        unordered_map<string,int>m;
        m[a]++;
        while(i<n)
        {
            a.erase(a.begin());
            a.push_back(s[i]);
            if(m.count(a))
            v.insert(a);
            m[a]++;
            i++;
        }
        vector<string>vec;
        for(auto it:v)vec.push_back(it);
        return vec;
    }
};