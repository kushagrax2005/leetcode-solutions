class Solution {
public:
    void f(int i,int t,int c,int sum,bool &flag,vector<int>&ma,vector<int>&vis)
    {
        if(flag)return;
        if(sum>t)return;
        if(sum==t)
        {
            c++;
            sum=0;
            i=ma.size()-1;
        }
        if(c==4)
        {flag=true;return;}
        if(i<0)return;
        if(!vis[i])
        {sum+=ma[i];
        vis[i]=1;
        f(i-1,t,c,sum,flag,ma,vis);
        sum-=ma[i];
        vis[i]=0;
        f(i-1,t,c,sum,flag,ma,vis);}
        else f(i-1,t,c,sum,flag,ma,vis);
    }
    bool makesquare(vector<int>& ma) {
        int i=0;
        int n=ma.size();
        int sum=0;
        // unordered_map<int,int>m;
        while(i<n)
        {
            sum+=ma[i];
            // m[ma[i]]++;
            i++;
        }
        if(sum%4)return false;
        int t=sum/4;
        bool flag=false;
        // int count=0;
        sum=0;
        int c=0;
        vector<int>vis(n,0);
        f(n-1,t,c,sum,flag,ma,vis);
        return flag;
    }
};