class Solution {
public:
    bool valid(string s)
    {
        stack<int>st;
        int i=0;
        while(i<s.size())
        {
            if(s[i]=='(')
            {
                st.push('(');
            }
            else
            {
                if(st.empty()) return false;
                st.pop();
            }
            i++;
        }
        if(st.empty())return true;
        return false;
    }
    void f(int n,string &s,vector<string>&v)
    {
        if(s.size()==2*n)
        {
            if(valid(s))v.push_back(s);
            return;
        }
        s.push_back(')');
        f(n,s,v);
        s.pop_back();
        s.push_back('(');
        f(n,s,v);
        s.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        string s="(";
        vector<string>v;
        f(n,s,v);
        return v;
    }
};