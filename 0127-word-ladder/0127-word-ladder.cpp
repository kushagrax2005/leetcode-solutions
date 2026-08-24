class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& w) {
        unordered_map<string,int>m;
        int n=w.size();
        for(int i=0;i<n;i++)
        {
            m[w[i]]=i;
        }
        if(!m.count(endWord))return 0;
        vector<int>vis(n,0);
        string node=beginWord;
        int ans=1;
        queue<string>q;
        q.push(node);
        // vis[m[node]]=1;
        
        while(!q.empty())
        {
            int sq=q.size();
            while(sq--)
            {
            node=q.front();
            q.pop();
            if(node==endWord)return ans;
            for(int i=0;i<w[0].size();i++)
            {
                for(int j=0;j<26;j++)
                {
                    string s=node;
                    char a='a'+j;
                    if(a==s[i])continue;
                    s[i]=a;
                    if(m.count(s)&&!vis[m[s]])
                    {
                        q.push(s);
                        vis[m[s]]=1;
                    }
                }
            }

            }
            ans++;
        }
        return 0;

    }
};