class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long k = (long long)k1 + k2;

        vector<int> diff(n);
        int mx = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            mx = max(mx, diff[i]);
        }

        if (k >= accumulate(diff.begin(), diff.end(), 0LL)) {
            return 0;
        }

        vector<long long> freq(mx + 1, 0);

        for (int x : diff) {
            freq[x]++;
        }

        for (int i = mx; i > 0 && k > 0; i--) {
            long long count = freq[i];
            long long use = min(k, count);

            freq[i] -= use;
            freq[i - 1] += use;
            k -= use;
        }

        long long ans = 0;

        for (int i = 1; i <= mx; i++) {
            ans += 1LL * i * i * freq[i];
        }

        return ans;
    }
};