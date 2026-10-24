
class Solution {
public:
    int countDaysTogether(string aa, string al, string ba, string bl) {
        string s = max(aa, ba);
        string e = min(al, bl);

        if(s > e) return 0;

        vector<int>v={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        int m1=(s[0]-'0')*10+s[1]-'0';
        int d1=(s[3]-'0')*10+s[4]-'0';
        int m2=(e[0]-'0')*10+e[1]-'0';
        int d2=(e[3]-'0')*10+e[4]-'0';

        int ans=0;

        if(m1==m2) return d2-d1+1;

        ans+=v[m1-1]-d1+1;

        for(int i=m1+1;i<m2;i++)
            ans+=v[i-1];

        ans+=d2;

        return ans;
    }
};
