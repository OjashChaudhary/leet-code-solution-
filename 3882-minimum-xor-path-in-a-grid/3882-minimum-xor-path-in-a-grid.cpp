class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int total = 1024;

        vector<vector<bool>> dp(n, vector<bool>(total, false));
        dp[0][0] = true;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                vector<bool> cur(total, false);

                if (i == 0 && j == 0) {
                    cur[grid[i][j]] = true;
                } else {
                    if (i > 0) {
                        for (int x = 0; x < total; x++) {
                            if (dp[j][x])
                                cur[x ^ grid[i][j]] = true;
                        }
                    }

                    if (j > 0) {
                        for (int x = 0; x < total; x++) {
                            if (dp[j - 1][x])
                                cur[x ^ grid[i][j]] = true;
                        }
                    }
                }

                dp[j] = cur;
            }
        }

        for (int x = 0; x < total; x++) {
            if (dp[n - 1][x])
                return x;
        }

        return 0;
    }
};