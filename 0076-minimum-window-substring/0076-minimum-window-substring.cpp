class Solution {
public:
    string minWindow(string s, string t) {
        int mm=s.size();
        int n=t.size();
        unordered_map<char,int>m;
        int i=0;
        int size=INT_MAX;
        string ans="";
        while(i<n)
        {
            m[t[i]]++;
            i++;
        }
        deque<char>d;
        i=0;
        int c=0;
        while(i<mm)
        {
            if(d.empty())
            {
                if(m.count(s[i]))
                {
                    d.push_back(s[i]);
                    m[s[i]]--;
                    c++;
                }
            }
            else
            {
                d.push_back(s[i]);
                if(m.count(s[i]))
                {
                    m[s[i]]--;
                    if(m[s[i]]>=0)c++;
                    else
                    {
                        while(!m.count(d.front())||m[d.front()]<0)
                        {
                            char a=d.front();
                            d.pop_front();
                            if(m.count(a))
                            {
                            m[a]++;}
                        }
                    }
                }
            }
            if(c==n&&d.size()<size)
            {
                size=d.size();
                ans="";
                for(char x:d)
                {
                    ans.push_back(x);
                }
            }
            i++;
        }
        return ans;
    }
};