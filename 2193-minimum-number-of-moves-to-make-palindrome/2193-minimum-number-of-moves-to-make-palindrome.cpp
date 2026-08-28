class Solution {
public:
    void f(string &c,int &ans)
    {
        int n=c.size();
        if(n==0||n==1)return;
        int i=0;
        int j=n-1;
        while(j>i && c[i] != c[j])j--;

        if (j == i)
        {
            ans += n / 2;
            c.erase(i, 1);
            f(c, ans);
            return;
        }
        
        // int a=n-1;
        // int b=n-2;
        // while(b>=0&&c[a]!=c[b])b--;

        // if (b<0)
        // {
        //     ans += n / 2;
        //     c.erase(a, 1);
        //     f(c, ans);
        //     return;
        // }
        
        int x=n-1-j;
        // int y=b;
        ans+=x;
        c.erase(j,1);
        c.erase(i,1);
        // else
        // {
        // ans+=y;
        // c.erase(a,1);
        // c.erase(b,1);
        // }
        f(c,ans);
    }
    int minMovesToMakePalindrome(string s) {
        int ans=0;
        f(s,ans);
        return ans;
    }
};