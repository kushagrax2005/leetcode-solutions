class Solution {
public:
    int f(vector<int>&v,int n)
    {
        int mini=INT_MAX;
        int p=0;
        int i=0;
        int c=1;
        bool flag=false;
        while(i<v.size())
        {
            if(mini>v[i])
            {
                mini=v[i];
                c=1;
                p=i;
            }
            else if(v[i]==v[i-1]+1)
            {
                c++;
            }
            else return -1;
            if(c==n){flag=true;break;}
            i++;
        }
        if(!flag)return -1;
        return p;
    }
    int ff(vector<int>&v,int n)
    {
        int maxi=-1;
        int p=0;
        int i=0;
        int c=1;
        bool flag=false;
        while(i<v.size())
        {
            if(maxi<v[i])
            {
                maxi=v[i];
                c=1;
                p=i;
            }
            else if(v[i]==v[i-1]-1)
            {
                c++;
            }
            else return -1;
            if(c==n){flag=true;break;}
            i++;
        }
        if(!flag)return -1;
        return min(p,n-p);
    }
    int minOperations(vector<int>& nums) {
        vector<int>v=nums;
        int n=nums.size();
        int i=0;
        while(i<n)
        {
            v.push_back(nums[i]);
            i++;
        }
        int a=f(v,n);
        int b=ff(v,n);
        if(a!=-1)return min(a,n-a+2);
        else if (b!=-1)return b+1;
        return -1;
    }
};