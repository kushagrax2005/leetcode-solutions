class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int d0 = 1, d1 = 1, ans = 1;

        for (int i = 1; i < n; i++) {
            int diff = nums[i] - nums[i - 1];

            switch (diff) {
                case 0:
                    d1 = d0 + 1;
                    break;
                case 1:
                    d0++;
                    d1++;
                    break;
                case 2:
                    d0 = d1 + 1;
                    d1 = 1;
                    break;
                default:
                    d0 = d1 = 1;
            }

            ans = max(ans, max(d0, d1));
        }

        return ans;
    }
};