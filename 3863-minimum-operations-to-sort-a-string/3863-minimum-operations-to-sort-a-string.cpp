class Solution {
public:
    int minOperations(string s) {
        string a=s;
        int n=s.size();
        sort(a.begin(),a.end());
        unordered_map<char,int>m;
        int c=0;
        for(int i=0;i<n;i++)
        {
            if(!m.count(s[i]))c++;
            m[s[i]]++;
        }
        if(n==1)return 0;
        if(n==2)
        {
            if(a==s)return 0;
            return -1;
        }
        if(a==s)return 0;
        // if(a[0]==s[0] || a[n-1]==s[n-1])return -1;
        if(a[0]==s[n-1] && a[n-1]==s[0]) {if(m[a[0]] > 1 || m[a[n-1]] > 1)return 2;return 3;}
        else if(a[0]==s[0] || a[n-1]==s[n-1])return 1;
        return 2;
    }
};