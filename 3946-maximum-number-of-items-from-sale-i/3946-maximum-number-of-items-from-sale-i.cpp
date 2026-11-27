class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int minPrice = INT_MAX;

        vector<int> freeItems(n, 0);

        for (int i = 0; i < n; i++) {
            minPrice = min(minPrice, items[i][1]);

            for (int j = 0; j < n; j++) {
                if (i != j && items[j][0] % items[i][0] == 0) {
                    freeItems[i]++;
                }
            }
        }

        vector<int> dp(budget + 1, 0);

        for (int i = 0; i < n; i++) {
            int price = items[i][1];
            int gain = freeItems[i] + 1;

            for (int b = budget; b >= price; b--) {
                dp[b] = max(dp[b], dp[b - price] + gain);
            }
        }

        int ans = 0;

        for (int b = 0; b <= budget; b++) {
            int extra = (budget - b) / minPrice;
            ans = max(ans, dp[b] + extra);
        }

        return ans;
    }
};
