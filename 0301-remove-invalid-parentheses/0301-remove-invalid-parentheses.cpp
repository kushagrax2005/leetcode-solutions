class Solution {
public:
    bool valid(string s)
    {
        int c = 0;

        for(char ch : s)
        {
            if(ch == '(')
                c++;
            else if(ch == ')')
            {
                c--;
                if(c < 0)
                    return false;
            }
        }

        return c == 0;
    }
    void f(int aa,int i,string &a,string &s,set<string>&v)
    {
        int cnt = 0;
    while(i < s.size() && s[i]!='(' && s[i]!=')')
    {
        a.push_back(s[i]);
        i++;
        cnt++;
    }
    if(a.size() == s.size() - aa || i == s.size())
    {
        if(a.size() == s.size() - aa && valid(a))
            v.insert(a);
            while(cnt--)a.pop_back();
        return;
    }
    a.push_back(s[i]);
    f(aa,i+1,a,s,v);
    a.pop_back();
    f(aa,i+1,a,s,v);
    while(cnt--)a.pop_back();
}

    vector<string> removeInvalidParentheses(string s) {
        int i=0;
        int n=s.size();
        int c=0;
        int ans=0;
        while(i<n)
        {
            if(s[i]=='(')c++;
            else if (s[i]==')')c--;
            if(c<0){ans++;c=0;}
            i++;
        }
        ans+=c;
        string a="";
        set<string>v;
        int b=0;
        f(ans,0,a,s,v);
        vector<string>vv;
        for(string ss:v)vv.push_back(ss);
    return vv;
    }
};