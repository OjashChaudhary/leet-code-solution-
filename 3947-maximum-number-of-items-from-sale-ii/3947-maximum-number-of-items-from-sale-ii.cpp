class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int maxFactor = n;

        vector<int> freq(maxFactor + 1, 0);
        vector<int> gain(maxFactor + 1, 0);

        int minPrice = INT_MAX;

        for (auto &x : items) {
            freq[x[0]]++;
            minPrice = min(minPrice, x[1]);
        }

        for (int i = 1; i <= maxFactor; i++) {
            for (int j = i; j <= maxFactor; j += i) {
                gain[i] += freq[j];
            }
            gain[i]--;
        }

        sort(items.begin(), items.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        long long ans = 0;
        long long rem = budget;

        for (auto &x : items) {
            int factor = x[0];
            int price = x[1];

            if (price >= 2LL * minPrice)
                break;

            long long take = min((long long)gain[factor],
                                 rem / price);

            ans += 2LL * take;
            rem -= take * price;
        }

        ans += rem / minPrice;

        return (int)ans;
    }
};
