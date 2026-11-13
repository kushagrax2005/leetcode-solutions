class Solution {
public:
    vector<long long> pref, suf_cost;
    vector<int> next_ge;
    int last_peak = 0;

    void precompute(vector<int>& nums) {
        int n = nums.size();
        pref.assign(n + 1, 0);
        for (int idx = 0; idx < n; idx++) {
            pref[idx + 1] = pref[idx] + nums[idx];
        }

        next_ge.assign(n, n);
        suf_cost.assign(n + 1, 0);
        vector<int> st;

        for (int idx = n - 1; idx >= 0; idx--) {
            while (!st.empty() && nums[st.back()] < nums[idx]) {
                st.pop_back();
            }
            if (!st.empty()) next_ge[idx] = st.back();
            st.push_back(idx);

            int nxt = next_ge[idx];
            long long flat_cost = 1LL * nums[idx] * (nxt - idx) - (pref[nxt] - pref[idx]);
            suf_cost[idx] = flat_cost + suf_cost[nxt];
        }
    }

    long long f(int i, int j, vector<int>& nums, int& maxi) {
        if (i >= j) {
            maxi = 0;
            return 0;
        } 
        if (last_peak < i) {
            last_peak = i;
            while (next_ge[last_peak] < j) {
                last_peak = next_ge[last_peak];
            }
        }
        maxi = nums[last_peak];
        long long cost_before_peak = suf_cost[i] - suf_cost[last_peak];
        long long cost_after_peak = 1LL * nums[last_peak] * (j - last_peak) - (pref[j] - pref[last_peak]);
        return cost_before_peak + cost_after_peak;
    }

    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        precompute(nums);

        int i = 0;
        long long ans = 0;
        int j = 0;
        int n = nums.size();
        int maxi = 0;
        last_peak = 0;

        while (i < n) {
            if (j == n) break;
            long long c = f(i, j, nums, maxi);

            while (j < n) {
                int new_maxi = max(maxi, nums[j]);
                long long add = (nums[j] < new_maxi) ? (new_maxi - nums[j]) : 0;
                if (c + add <= k) {
                    c += add;
                    if (nums[j] >= maxi) {
                        maxi = nums[j];
                        last_peak = j;
                    }
                    j++;
                } else {
                    break;
                }
            }
            ans += (j - i);
            i++;
        }

        if (j - i > 0) {
            long long rem = j - i;
            ans += (rem * (rem + 1LL)) / 2;
        }
        return ans;
    }
};