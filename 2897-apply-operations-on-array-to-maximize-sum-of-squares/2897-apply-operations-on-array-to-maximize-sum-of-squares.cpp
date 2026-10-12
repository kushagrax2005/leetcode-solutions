class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int a=nums[i];
            for(int j=0;j<32;j++)
            {
                if(a&1)
                {
                    m[j]++;
                }
                a=a>>1;
                if(a==0)break;
            }
        }
        int mod=1e9+7;
        long long ans=0;
        for(int i=0;i<k;i++)
        {
            long long a=0;
        for(int b=0;b<32;b++)
        {
            if(m[b]>0)
            {
                a+=(1<<b);
                m[b]--;
            }   
        }
        ans=((a*a)%mod+ans)%mod;
        }
        return (int)ans;
    }
};