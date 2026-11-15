class Solution {
public:
int mod=1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        long long e=0;
        long long o=0;
        long long sum=0;
        int n=arr.size();
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            if(sum&1)
            {
                ans=(ans+e+1)%mod;
                o++;
            }
            else 
            {
                ans=(ans+o)%mod;
                e++;
            }
        }
        // int i=n-1;
        // while(i--)
        // {
        //     if(sum&1)
        //     {
        //         sum-=arr[i];
        //         o--;
        //         ans+=e;
        //     }
        //     else
        //     {
        //         sum-=arr[i];
        //         e--;
        //         ans+=o;
        //     }
        // }
        return (int)ans;
    }
};