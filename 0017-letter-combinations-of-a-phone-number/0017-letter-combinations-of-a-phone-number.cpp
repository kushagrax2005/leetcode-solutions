class Solution {
public:
    void f(int i,string &d,string &vis,unordered_map<char,string>&m,vector<string>&vec)
    {
        if(i==d.size())
        {
            vec.push_back(vis);
            return;
        }
            for(auto it:m[d[i]])
            {
                vis.push_back(it);
                f(i+1,d,vis,m,vec);
                vis.pop_back();
            }
    }
    vector<string> letterCombinations(string d) {
        unordered_map<char,string>m;
        int j=0;
        for(int i=2;i<10;i++)
        {
            for(int k=0;k<3;k++)
            {
            m['0'+i].push_back('a'+j);
            j++;
            }
            if(i==7||i==9){m['0'+i].push_back('a'+j);j++;}
        }
        vector<string>vec;
        string vis="";
        f(0,d,vis,m,vec);
        return vec;
    }
};