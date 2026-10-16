class Solution {
public:
    bool f(int i,int t,int c,int sum,vector<int>&ma,vector<int>&vis)
    {
        if(c==4){return true;}
        if(sum>t)return false;
        if(sum==t)
        {
            return f(ma.size()-1,t,c+1,0,ma,vis);
        }
        if(i<0)return false;
        
        if(!vis[i])
        {
            vis[i]=1;
            if(f(i-1,t,c,sum+ma[i],ma,vis))return true;
            vis[i]=0;
        }
        // return false;
        return f(i-1,t,c,sum,ma,vis);
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
        // vector<int>
        return f(n-1,t,c,sum,ma,vis);
        // return flag;
    }
};