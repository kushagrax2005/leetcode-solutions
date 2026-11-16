class Solution {
public:
    string f(string s,int k)
    {
        string a="";
        int aa=0;
        for(int i=0;i<s.size();i++)
        {
            aa+=s[i]-'0';
            if (((i+1)%k)==0)
            {
                a+=to_string(aa);
                aa=0;
            }
        }
        if((s.size())%k)a+=to_string(aa);
        return a;
    }
    string digitSum(string s, int k) {
        while(s.size()>k)
        {
            s=f(s,k);
        }
        return s;
    }
};