class Solution {
public:
    void back_track(string a,string b,unordered_map<string,vector<string>>&vv,vector<string>&v,vector<vector<string>>&ans)
    {
        if(a==b)
        {
            vector<string> temp = v;
            reverse(temp.begin(), temp.end()); // Reverse because we walked endWord -> beginWord
            ans.push_back(temp);
            return;
        }
        for(auto it:vv[a])
        {
            v.push_back(it);
            back_track(it,b,vv,v,ans);
            v.pop_back();
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& w) {
        unordered_map<string, int> m;
        int i = 0;
        int n = w.size();
        
        while (i < n) {
            m[w[i]] = i+1;
            i++;
        }
        if (!m.count(beginWord)) {
            m[beginWord] = 0;
        }
        if (!m.count(endWord))
            return {};
        vector<int> vis(n, 0);
        queue<string> q;
        string s = beginWord;
        q.push(s);
        int c = 0;
        // int ans = 1;

        unordered_map<string,vector<string>>vv;
        vector<int>l(n+1,1e9);
        l[m[beginWord]] = 0;
        bool flag =false;
        while (!q.empty()) {
            int sz = q.size();
            for (int k = 0; k < sz; k++) {
                s = q.front();
                q.pop();
                if(s==endWord)flag=true;
                for (i = 0; i < beginWord.size(); i++) {
                    string ss=s;
                    for (int j = 0; j < 26; j++) {
                        ss[i] = 'a' + j;
                        if(ss[i]==s[i])continue;
                        if (m.count(ss) && l[m[s]] + 1 < l[m[ss]]) 
                            {
                                l[m[ss]] = l[m[s]] + 1;
                                vv[ss].clear();
                                vv[ss].push_back(s);
                                q.push(ss);
                            }
                            else if (m.count(ss) && l[m[s]] + 1 == l[m[ss]])
                            {
                                vv[ss].push_back(s);
                            }
                    }
                }
            }
            if(flag)break;
            }
        // return 0;
        if(!flag)return {};
        vector<vector<string>>ans;
        vector<string>vvv;
        vvv.push_back(endWord);
        back_track(endWord,beginWord,vv,vvv,ans);
        return ans ;
    }
};