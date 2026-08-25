class Solution {
public:
    void dfs(string node,string beginWord,unordered_map<string,vector<string>>&con,vector<vector<string>>&vec,vector<string>&v)
    {
        if(node==beginWord)
        {
            vector<string> temp = v;
            reverse(temp.begin(), temp.end());
            vec.push_back(temp);
            return;
        }
        for(string it:con[node])
        {
            v.push_back(it);
            dfs(it,beginWord,con,vec,v);
            v.pop_back();
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& w) {
        int n=w.size();
        unordered_map<string,int>m;
        for(int i=0;i<n;i++)
        {
            m[w[i]]=i;
        }
        if(!m.count(endWord))return {};
        queue<string>q;
        string node=beginWord;
        q.push(node);
        // vector<int>vis(n,0);
        unordered_map<string,int>level;
        bool flag=false;
        unordered_map<string,vector<string>>con;
        while(!q.empty())
        {
            node=q.front();
            q.pop();
            if(node==endWord)flag=true;
            for(int i=0;i<w[0].size();i++)
            {
                for(int j=0;j<26;j++)
                {
                    string s=node;
                    char a='a'+j;
                    if(s[i]==a)continue;
                    s[i]=a;
                    // if(m.count(s) && !vis[m[s]])
                    // {
                    //     q.push(s);
                    //     vis[m[s]]=1;
                    //     con[s].push_back(node);
                    // }
                    if(m.count(s))
                    {
                        if(!level.count(s))
                        {
                            level[s] = level[node] + 1;
                            q.push(s);
                            con[s].push_back(node);
                        }
                        else if(level[s] == level[node] + 1)
                        {
                            con[s].push_back(node);
                        }
                    }
                }
            }
        }
        if(!flag)return {};
        int k=1;
        node=endWord;
        // while(node!=beginWord)
        // {
        //     int aa=m[node]
        // }
        vector<string>v;
        v.push_back(node);
        vector<vector<string>>vec;
        dfs(node,beginWord,con,vec,v);
        return vec;
    }
};