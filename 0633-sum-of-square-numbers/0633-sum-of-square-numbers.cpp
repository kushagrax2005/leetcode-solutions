class Solution {
public:
    bool judgeSquareSum(int c) {
        long long a=0;
        long long b=sqrt(c);
        while(a<=b)
        {
            long long d=a*a+b*b;
            if(c==d)return true;
            else if(c<d)b--;
            else a++;
        }
        return false;
    }
};