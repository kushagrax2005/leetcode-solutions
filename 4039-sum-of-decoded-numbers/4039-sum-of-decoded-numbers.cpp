class Solution {
public:
    long long mod=1e9+7;
    // long long f(long long d)
    // {
    //     long long a=1;
    //     while(d)
    //     {
    //         a=a*10;
    //         d=d/10;
    //     }

    // }
    long long power(long long a,long long b,long long result)
    {
        while(b)
        {
            if(b&1)result=(result*a)%mod;
            a=(a*a)%mod;
            b=b>>1;
        }
        return result;
    }
    int sumDecoded(vector<long long>& nums) {
        long long ans=0;
        for(int i=0;i<nums.size();i++)
        {
            long long d=nums[i]/10;
            string dd=to_string(d);
            long long w=nums[i]%10;
            long long y=0;
            int n=dd.size()-w;
            long long ii=1;
            while(n)
            {
                y+=d%10*ii;
                ii=ii*10;
                d=d/10;
                n--;
            }
            ans+=power(d,y,1);
        }
        return ans%mod;
    }
};