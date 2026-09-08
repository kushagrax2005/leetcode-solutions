class Solution {
public:
    string smallestNumber(string p) {
        string s="";
        int i=0;
        while(i<=p.size())
        {
            s.push_back('1'+i);
            i++;
        }
        i=0;
        while(i<p.size())
        {
            if(p[i]=='I'){i++;continue;}
            int j=i;
            while(j<p.size()&&p[j]=='D')
            {
                j++;
            }
            // j--;
            reverse(s.begin()+i,s.begin()+j+1);
            i=j+1;
        }
        return s;
    }
};