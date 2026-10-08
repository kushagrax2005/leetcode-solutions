class Solution {
public:
    string removeOuterParentheses(string s) {
        int i=0;
        int n=s.size();
        stack<char>st;
        string a="";
        int c=0;
        while(i<n)
        {
            if(s[i]=='(')
            {
                st.push(s[i]);
                c++;
            }
            else
            {
                st.push(s[i]);
                c--;
            }
            if(c==0)
            {
                st.pop();
                    string aa="";
                    while(st.size()!=1)
                    {
                        aa=st.top()+aa;
                        st.pop();
                    }
                    a=a+aa;
                st.pop();
            }
            i++;
        }
        // reverse(a.begin(),a.end());
        return a;
    }
};