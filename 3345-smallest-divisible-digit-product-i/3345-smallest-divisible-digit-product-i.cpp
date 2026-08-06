class Solution {
public:
    long long pro(int n)
    {
        long long ans=1;
        while(n)
        {
            ans*=(n%10);
            n=n/10;
        } 
        return ans;
    }
    int smallestNumber(int n, int t) {
        int i=n;
        while(i<=100)
        {
            if(pro(i)%t==0)return i;
            i++;
        }
        return -1;
    }
};