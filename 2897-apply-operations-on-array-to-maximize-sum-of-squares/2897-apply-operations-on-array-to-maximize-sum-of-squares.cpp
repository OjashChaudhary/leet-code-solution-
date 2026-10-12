class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        long long ans = 0;

        for (int b = 0; b < 30; b++) {
            int cnt = 0;

            for (int x : nums) {
                if (x & (1 << b))
                    cnt++;
            }

            if (cnt > 0) {
                // Count set bits for constructing the maximum values
            }
        }

        vector<int> bits(30, 0);

        for (int x : nums) {
            for (int b = 0; b < 30; b++) {
                if (x & (1 << b))
                    bits[b]++;
            }
        }

        for (int i = 0; i < k; i++) {
            long long x = 0;

            for (int b = 0; b < 30; b++) {
                if (bits[b] > 0) {
                    x |= (1LL << b);
                    bits[b]--;
                }
            }

            ans = (ans + x * x) % MOD;
        }

        return ans;
    }
};