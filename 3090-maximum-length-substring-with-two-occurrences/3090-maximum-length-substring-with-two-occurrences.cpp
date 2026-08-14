class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.size();
        unordered_map<char,int>m;
        int i=0;
        int j=0;
        int maxi=0;
        while(j<n)
        {
            m[s[j]]++;
            if(m[s[j]]==3)
            {
                while(m[s[j]]==3)
                {m[s[i]]--;
                i++;}
            }
            maxi=max(maxi,j-i+1);
            j++;
        }
        return maxi;
    }
};