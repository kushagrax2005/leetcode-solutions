class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int i=0;
        int n=arr.size();
        vector<int>pre(n,0);
        pre[0]=arr[i];
        i++;
        while(i<n)
        {
            pre[i]=pre[i-1]+arr[i];
            i++;
        }
        i=0;
        int ans=0;
        while(i<n)
        {
            int a=0;
            int j=-1;
            if(i&1) j=0;
            while(j<i)
            {
                if(j>=0)a=pre[j];
                ans+=pre[i]-a;
                j+=2;
            }
            i++;
        }
        return ans;
    }
};