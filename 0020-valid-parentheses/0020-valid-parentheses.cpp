class Solution {
public:
    bool isValid(string s) {
        int i=0;
        int n=s.size();
        stack<int>st;
        while(i<n)
        {
            char a=s[i];
            if(a=='{'||a=='['||a=='(')
            {
                st.push(a);
            }
            else if(a=='}'&&!st.empty()&&st.top()=='{')
            {
                st.pop();
            }
            else if(a==']'&&!st.empty()&&st.top()=='[')
            {
                st.pop();
            }
            else if(a==')'&&!st.empty()&&st.top()=='(')
            {
                st.pop();
            }
            else return false;
            i++;
        }
        if(!st.empty())return false;
        return true;
    }
};