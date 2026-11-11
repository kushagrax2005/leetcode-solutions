class Solution {
public:
    long long minimumCost(int c1, int c2, int cb, int n1, int n2) {
        long long ans=0;
        if(cb<=c1+c2)
        {
            int a=min(n1,n2);
            n1-=a;
            n2-=a;
            ans+=(long long)cb*(long long)a;
        }
        if(n1!=0)
        {
            ans+=(long long)min(cb,c1)*(long long)n1;
        }
        if(n2!=0) ans+=(long long)min(cb,c2)*(long long)n2;
        return ans; 
    }
};