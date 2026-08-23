class Solution {
public:
    bool sumGame(string num) {
        int i=0;
        int n=num.size();
        int l=0;
        int r=0;
        int r_sum=0;
        int l_sum=0;
        while(i<n)
        {
            if(i<n/2)
            {
                if(num[i]=='?')l++;
                else l_sum+=(num[i]-'0');
            }
            else
            {
                if(num[i]=='?')r++;
                else r_sum+=(num[i]-'0');
            }
            i++;
        }
        if ((l + r) % 2 == 1)
            return true;

        return (l_sum - r_sum) != 9 * (r - l) / 2;

    }
};