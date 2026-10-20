class Solution {
public:
    int ff(vector<int>nums,vector<int>&v,int i)
    {
        int n=nums.size();
        int dec=0;
        for(int j=0;j<n;j+=i)
        {
            // sort(nums.begin()+j,nums.begin()+j+i);//
            vector<int>a;
            for(int k=j;k<j+i;k++)
            {
                a.push_back(nums[k]);
            }
            int l=a.size();
            int mini=0;
            int mini_2=0;
            bool flag=true;
            bool flag_2=true;
            a.push_back(a[0]);
            for(int k=1;k<l;k++)
            {
                // mini=a[mini]>a[k]?k:mini;
                // mini_2=a[mini_2]>=a[k]?k:mini_2;
                if(a[k-1]>a[k])mini=k;
                a.push_back(a[k]);
            }
            l=0;
            while(l<i-1)
            {
                if(a[mini]>a[mini+1]){return 0;}
                mini++;
                l++;
            }
            // l=0;
            // while(l<i-1)
            // {
            //     if(a[mini_2]>a[mini_2+1]){flag_2=false;break;}
            //     mini_2++;
            //     l++;
            // }
            // if(flag==false&&flag_2==false)return 0;
             sort(nums.begin()+j,nums.begin()+j+i);
        }
        if(nums==v)return i;
        return 0;
    }
    vector<int> f(int n)
    {
        vector<int>v;
        for(int i=1;i*i<=n;i++)
        {
            if(n%i==0)
            {
                v.push_back(i);
                if(n/i != i)
                v.push_back(n/i);
            }
        }
        sort(v.begin(),v.end());
        return v;
    }
    int sortableIntegers(vector<int>& nums) {
        vector<int>v=nums;
        int n=nums.size();
        sort(v.begin(),v.end());
        vector<int>d=f(n);
        int ans=0;
        for(int i=0;i<d.size();i++)
        {
            ans+=ff(nums,v,d[i]);
        }
        return ans;
    }
};