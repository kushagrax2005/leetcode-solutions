class Solution {
public:
    bool canAliceWin(int n) {
        bool flag=false;
        int i=10;
        while(n>=i)
        {
            flag=!flag;
            n-=i;
            i--;
        }
        // if(n==0)return false;
        if(flag)return true;
        return false;
    }
};