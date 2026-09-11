class Solution {
public:
    int fac(int n)
    {
        int ans=1;
        while(n>1)
        {
            ans=ans*n;
            n--;
        }
        return ans;
    }
    int totalNumbers(vector<int>& d) {
        int e=0;
        int t=0;
        int i=0;
        int n=d.size();
        unordered_map<int,int>m;
        // vector<int>v(10,0);
        while(i<n)
        {
            if(d[i]%2==0&&!m.count(d[i]))
            {
                e++;
            }
            m[d[i]]++;
            t++;
            i++;
        }
        int ans = 0;
        for(auto &a:m)
        {
            if(a.first%2==0)
            {
                a.second--;
                for(auto &b:m)
                {
                    if(b.second!=0 && b.first!=0)
                    {
                        b.second--;
                        for(auto &c:m)
                        {
                            if(c.second!=0)ans++;
                        }
                        b.second++;
                    }
                }
                a.second++;
            }
        }
        return ans;
    }
};