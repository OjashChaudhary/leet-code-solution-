class Solution {
public:
    int numTrees(int n) {
        long long dp[n + 1];
        dp[0] = 1;

        for (int nodes = 1; nodes <= n; nodes++) {
            dp[nodes] = 0;

            for (int root = 1; root <= nodes; root++) {
                dp[nodes] += dp[root - 1] * dp[nodes - root];
            }
        }

        return (int)dp[n];
    }
};