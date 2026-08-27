class Solution {
public:
    string f(int i,string &s)
    {
        int n=s.size();
        int a=i;
        int b=i+1;
        int aa=i-1;
        int bb=i+1;
        while(aa>=0&&bb<n)
        {
            if(s[aa]!=s[bb]) break;
            aa--;
            bb++;
        }
        aa++;
        bb--;
        while(a>=0&&b<n)
        {
            if(s[a]!=s[b]) break;
            a--;
            b++;
        }
        a++;
        b--;
        if(bb-aa+1>b-a+1)
        return s.substr(aa,bb-aa+1);
        return s.substr(a,b-a+1);
    }
    string longestPalindrome(string s) {
        string ans="";
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            string ss=f(i,s);
            if(ans.size()<ss.size())ans=ss;
        }
        return ans;
    }
};