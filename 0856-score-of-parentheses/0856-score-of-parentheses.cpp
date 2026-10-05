class Solution {
public:
    int scoreOfParentheses(string s) {
        int ans=0;
        int i=0;
        int n=s.size();
        stack<int>st;
        while(i<n)
        {
            if(s[i]=='(')
            {
                st.push(0);
            }
            else
            {
                int a=st.top();
                st.pop();
                if(a==0)a=1;
                else a=a*2;
                if(st.empty())st.push(a);
                else
                st.top()+=a;
            }
            i++;
        }
        return st.top();
    }
};