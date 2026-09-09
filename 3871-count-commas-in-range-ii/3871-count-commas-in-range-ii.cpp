class Solution {
public:
    long long countCommas(long long n) {
       long long ans=0;
       long long a=pow(10,3)-1;
       int b=3;
       while(n>a)
       {
        ans+=n-a;
        b+=3;
        a=pow(10,b)-1;
       }
       return ans;
    }
};