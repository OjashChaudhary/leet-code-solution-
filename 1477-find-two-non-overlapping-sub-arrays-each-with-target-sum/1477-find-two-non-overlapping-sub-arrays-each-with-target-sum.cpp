class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();

        vector<int> dp(n + 1, 1000000000);
        unordered_map<int, int> mp;

        mp[0] = -1;

        int sum = 0;
        int ans = 1000000000;
        int minLen = 1000000000;

        for (int i = 0; i < n; i++) {
            sum += arr[i];

            int need = sum - target;

            if (mp.find(need) != mp.end()) {
                int start = mp[need] + 1;
                int length = i - start + 1;

                if (start > 0) {
                    ans = min(ans, length + dp[start]);
                }

                minLen = min(minLen, length);
            }

            dp[i + 1] = minLen;

            mp[sum] = i;
        }

        if (ans == 1000000000) {
            return -1;
        }

        return ans;
    }
};