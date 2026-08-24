class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>& b)
    {
        if(i<0||i>=b.size()||j<0||j>=b[0].size())return;
        if(b[i][j]=='O')b[i][j]='0';
        else return;
        vector<pair<int,int>>v={{0,1},{0,-1},{1,0},{-1,0}};
        for(int k=0;k<4;k++)
        {
            dfs(i+v[k].first,j+v[k].second,b);
        }
    }
    void bfs(int i,int j,vector<vector<char>>&b)
    {
        if(b[i][j]!='O')return;
        int node=i*b[0].size()+j;
        queue<int>q;
        q.push(node);
        b[i][j]='0';
        vector<pair<int,int>>v={{0,1},{0,-1},{1,0},{-1,0}};
        while(!q.empty())
        {
            node=q.front();
            q.pop();
            int x=node/b[0].size();
            int y=node%b[0].size();
            for(int k=0;k<4;k++)
            {
                int aa=x+v[k].first;
                int bb=y+v[k].second;
                if(aa>=0&&aa<b.size()&&bb>=0&&bb<b[0].size()&&b[aa][bb]=='O')
                {
                    q.push(aa*b[0].size()+bb);
                    b[aa][bb]='0';
                }
            }
        }
    }
    void solve(vector<vector<char>>& b) {
         int m=b.size();
         int n=b[0].size();
        //  unordered_map<int,int>mm;
         for(int j=0;j<n;j++)
         {
            bfs(0,j,b);
            bfs(m-1,j,b);
         }
         for(int i=1;i<m-1;i++)
         {
            bfs(i,0,b);
            bfs(i,n-1,b);
         }
         for(int i=0;i<m;i++)
         {
            for(int j=0;j<n;j++)
            {
                if(b[i][j]=='O')b[i][j]='X';
                else if(b[i][j]=='0')b[i][j]='O';
            }
         }
         return ;
    }
};