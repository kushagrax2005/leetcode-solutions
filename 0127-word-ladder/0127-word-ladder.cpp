class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& w) {
        unordered_map<string, int> m;
        int i = 0;
        int n = w.size();
        while (i < n) {
            m[w[i]] = i;
            i++;
        }
        if (!m.count(endWord))
            return 0;
        vector<int> vis(n, 0);
        queue<string> q;
        string s = beginWord;
        q.push(s);
        int c = 0;
        int ans = 1;
        while (!q.empty()) {
            c = q.size();
            while (c--) {
                s = q.front();
                q.pop();
                if (s == endWord)
                    return ans;
                for (i = 0; i < beginWord.size(); i++) {
                    string ss=s;
                    for (int j = 0; j < 26; j++) {
                        ss[i] = 'a' + j;
                        if (m.count(ss) && !vis[m[ss]]) {
                            q.push(ss);
                            vis[m[ss]] = 1;
                        }
                    }
                }
            }
            ans++;
        }
        return 0;
    }
};