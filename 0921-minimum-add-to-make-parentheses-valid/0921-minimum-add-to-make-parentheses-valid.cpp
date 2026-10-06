class Solution {
public:
    int minAddToMakeValid(string s) {
        int i=0;
        int n=s.size();
        stack<char>st;
        while(i<n)
        {
            if(st.empty())st.push(s[i]);
            else
            {
                if(s[i]==')'&&st.top()=='(')
                {
                    st.pop();
                }
                else st.push(s[i]);
            }
            i++;
        }
        return st.size();
    }
};