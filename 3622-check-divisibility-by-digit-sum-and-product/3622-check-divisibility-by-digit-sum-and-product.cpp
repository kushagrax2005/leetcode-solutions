class Solution {
public:
    bool checkDivisibility(int n) {
        int m=n;
        int sum=0;
        int mul=1;
        while(m)
        {
            sum+=(m%10);
            mul*=(m%10);
            m=m/10;
        }
        return n%(sum+mul)==0?true:false;
    }
};