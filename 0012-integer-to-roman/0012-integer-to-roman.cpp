class Solution {
public:
    string intToRoman(int num) {
        string s="";
        unordered_map<int, char> m = {
            {1, 'I'},
            {5, 'V'},
            {10, 'X'},
            {50, 'L'},
            {100, 'C'},
            {500, 'D'},
            {1000, 'M'}
        };
        int i=1;
        while(num)
        {
            int a=num%10;
            num=num/10;
            if(a==4||a==9)
            {
                a*=i;
                s.push_back(m[a+i]);
                s.push_back(m[i]);
            }
            else
            {
                bool flag=false;
                if(a>=5)flag=true;
                a=a%5;
                for(int j=0;j<a;j++)
                {
                    s.push_back(m[i]);
                }
                if(flag)
                {
                    s.push_back(m[5*i]);
                }
            }
            i*=10;
        }
        reverse(s.begin(),s.end());
        return s;
    }
};