class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        deque<pair<int, int>> dq;

        long long cost = 0;
        long long ans = 0;
        int j = n - 1;

        for (int i = n - 1; i >= 0; i--) {
            int cnt = 1;

            while (!dq.empty() && dq.back().first < nums[i]) {
                int val = dq.back().first;
                int c = dq.back().second;
                dq.pop_back();

                cnt += c;
                cost += 1LL * (nums[i] - val) * c;
            }

            dq.push_back({nums[i], cnt});

            while (cost > k) {
                int val = dq.front().first;
                int c = dq.front().second;
                dq.pop_front();

                cost -= val - nums[j];
                j--;

                if (c > 1) {
                    dq.push_front({val, c - 1});
                }
            }

            ans += j - i + 1;
        }

        return ans;
    }
};
