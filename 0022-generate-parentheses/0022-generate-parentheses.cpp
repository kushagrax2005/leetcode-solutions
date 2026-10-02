class Solution {
public:
void f(int c,int i,int n,string &s,vector<string>&ans)
{
    if(c==n&&i==n)
    {
        ans.push_back(s);
        return;
    }    
    if(i<n)
    {
    s.push_back('(');
    i++;
    f(c,i,n,s,ans);
    i--;
    s.pop_back();
    }
    if(i>c)
    {
        s.push_back(')');
        c++;
        f(c,i,n,s,ans);
        c--;
        s.pop_back();
    }
}

vector<string> generateParenthesis(int n)
{
    vector<string> ans;
    string s = "";
    f(0, 0, n, s, ans);
    return ans;
}
};