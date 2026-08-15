class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        vector<int>vis(50*50,0);
        queue<int>q;
        q.push(50*sr+sc);
        vis[50*sr+sc]=1;
        int a=image[sr][sc];
        image[sr][sc]=color;
        vector<pair<int,int>>v={{-1,0},{0,-1},{1,0},{0,1}};
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(int j=0;j<4;j++)
            {
                int x=node/50+v[j].first;
                int y=node%50+v[j].second;
                if(x>=0&&x<m&&y>=0&&y<n&&image[x][y]==a&&!vis[50*x+y])
                {
                    vis[50*x+y]=1;
                    image[x][y]=color;
                    q.push(50*x+y);
                }
            }
        }
        return image;
    }
};