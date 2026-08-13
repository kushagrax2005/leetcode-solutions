class Solution {
public:
    void f(int n, string &s, int open, int close, vector<string>& ans)
{
    if(s.size() == 2*n)
    {
        ans.push_back(s);
        return;
    }

    if(open < n)
    {
        s.push_back('(');
        f(n, s, open+1, close, ans);
        s.pop_back();
    }

    if(close < open)
    {
        s.push_back(')');
        f(n, s, open, close+1, ans);
        s.pop_back();
    }
}

vector<string> generateParenthesis(int n)
{
    vector<string> ans;
    string s = "";

    f(n, s, 0, 0, ans);

    return ans;
}
};