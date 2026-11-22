class Solution {
public:
    bool checkString(string s) {
        int i=0;
        int n=s.size();
        bool flag=false;
        while(i<n)
        {
            if(!flag&&s[i]=='a')i++;
            else
            {
                flag=true;
                if(s[i]=='a')return false;
                i++;
            }
        }
        return true;
    }
};