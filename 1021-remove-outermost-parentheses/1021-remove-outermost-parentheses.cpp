class Solution {
public:
    string removeOuterParentheses(string s) {
        int i=0;
        int n=s.size();
        stack<char>st;
        string ss="";
        int flag=0;
        int flag2=0;
        while(i<n)
        {
            if(flag==0)
            {
                flag++;
                i++;continue;
            }
            else
            {
                if(s[i]=='(')
                {   
                    ss.push_back('(');
                    flag2++;
                }
                else if(flag2>0)
                {

                    ss.push_back(')');
                    flag2--;
                }
                else {flag=0;flag2=0;}
            }
            i++;
            }
            return ss;
    }
};