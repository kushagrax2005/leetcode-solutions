class Solution {
public:
    int minInsertions(string s) {
        int i=0;
        int n=s.size();
        int c=0;
        int ans=0;
        stack<char>st;
        while(i<n)
        {
            if(s[i]=='(')
            {
                st.push('(');
            }
            else
            {
                if(!st.empty())
                {
                    if(i+1==n||s[i+1]!=')')
                    {
                        ans++;
                    }
                    else i++;
                    st.pop();
                }
                else 
                {
                    st.push('(');
                    ans++;
                    i--;
                }
            }
            i++;
        }
        while(!st.empty())
        {
            ans+=2;
            st.pop();
        }
        return ans;
    }
};