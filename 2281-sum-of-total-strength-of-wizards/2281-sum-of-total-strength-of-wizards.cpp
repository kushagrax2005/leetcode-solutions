class Solution {
public:
        long long mod = 1e9 + 7;
    vector<long long> start_se(vector<int>& arr) {
        int n = arr.size();
        vector<long long> v(n, -1);
        stack<long long> st;
        int i = 0;
        while (i < n) {
            if (st.empty()) {
                st.push(i);
                i++;
            } else {
                if (arr[i] > arr[st.top()]) {
                    v[i] = st.top();
                    st.push(i);
                    i++;
                } else {
                    st.pop();
                }
            }
        }
        return v;
    }
    vector<long long> end_se(vector<int>& arr) {
        int n = arr.size();
        vector<long long> v(n, n);
        stack<long long> st;
        int i = n - 1;
        while (i >= 0) {
            if (st.empty()) {
                st.push(i);
                i--;
            } else {
                if (arr[i] >= arr[st.top()]) {
                    v[i] = st.top();
                    st.push(i);
                    i--;
                } else {
                    st.pop();
                }
            }
        }
        return v;
    }
    int totalStrength(vector<int>& arr) {
        int n = arr.size();
        vector<long long> v1 = start_se(arr);
        vector<long long> v2 = end_se(arr);
        vector<long long> pref(n, 0);
        pref[0] = arr[0]%mod;
        int i = 1;
        while (i < n) {
            pref[i] = (pref[i - 1] + arr[i]) % mod;
            i++;
        }

        // Your exact in-place prefix of prefix sum
        i = 1;
        while (i < n) {
            pref[i] = (pref[i] + pref[i - 1]) % mod;
            i++;
        }
        long long ans = 0;
        i = 0;
        while (i < n) {
            long long L = v1[i];
            long long R = v2[i];

            // Right sum: pref[i ... R - 1]
            long long right_sum = (((R == n) ? pref[n - 1] : pref[R - 1]) - ((i == 0) ? 0 : pref[i - 1]) + mod) % mod;

            // Left sum: pref[L ... i - 1]
            long long left_sum = (((i == 0) ? 0 : pref[i - 1]) - ((L <= 0) ? 0 : pref[L-1]) + mod) % mod;

            long long left_count = i - L;
            long long right_count = R - i;

            // Must subtract: (left_count * right_sum) - (right_count * left_sum)
            long long total_sub_sum = (left_count * right_sum % mod - right_count * left_sum % mod + mod) % mod;

            ans = (ans + arr[i] * total_sub_sum) % mod;
            i++;
        }
        return ans;
    }
};