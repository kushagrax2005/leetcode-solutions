class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n=s.size();
        int i=0;
        string ss(n,'1');
        int j=0;
        int kk=0;
        bool flag=false;
        while(j<n)
        {
            if(s[j]=='1')kk++;
            while(kk>k)
            {
                if(s[i]=='1')kk--;
                i++;
            }
            if(kk==k)
            {
                while(s[i]=='0')i++;
                if(ss.size()>s.substr(i,j-i+1).size())ss=s.substr(i,j-i+1);
                else if(ss.size()==s.substr(i,j-i+1).size())
                ss=s.substr(i,j-i+1)<ss?s.substr(i,j-i+1):ss;
                flag=true;
            }
            j++;
        }
        if(!flag)return "";
        // i=0;
        // while(ss[i]=='0')
        // {
        //     i++;
        // }
        // ss=ss.substr(i,ss.size()-i+1);
        if(flag)return ss;
        return ss;
    }
};