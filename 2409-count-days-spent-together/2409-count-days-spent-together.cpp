class Solution {
public:
    int countDaysTogether(string aa, string al, string ba, string bl) {
        vector<int>v={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int i=0;
        int ans=0;
        if(aa <= ba)
        {
            if(al<ba)return 0;
            string a=al<bl?al:bl;
            //ba,a
            int m1=(ba[0]-'0')*10+ba[1]-'0';
            int d1=(ba[3]-'0')*10+ba[4]-'0';
            int m2=(a[0]-'0')*10+a[1]-'0';
            int d2=(a[3]-'0')*10+a[4]-'0';
            int i=m1+1;
            if(m1==m2){return d2-d1+1;}
            while(i<m2)
            {
                ans+=v[i-1];
                i++;
            }
            ans+=v[m1-1]-d1+1;
            ans+=d2;
        }
        else
        {
            if(bl<aa)return 0;
            string a=al<bl?al:bl;
            //aa,a
            int m1=(aa[0]-'0')*10+aa[1]-'0';
            int d1=(aa[3]-'0')*10+aa[4]-'0';
            int m2=(a[0]-'0')*10+a[1]-'0';
            int d2=(a[3]-'0')*10+a[4]-'0';
            int i=m1+1;
            if(m1==m2){return d2-d1+1;}
            while(i<m2)
            {
                ans+=v[i-1];
                i++;
            }
            ans+=v[m1-1]-d1+1;
            ans+=d2;
        }
        return ans;
    }
};