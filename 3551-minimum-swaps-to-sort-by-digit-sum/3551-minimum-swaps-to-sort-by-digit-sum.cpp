
class Solution {
public:
    int digitSum(int x) {
        int sum = 0;

        while (x > 0) {
            sum += x % 10;
            x /= 10;
        }

        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<pair<int, int>> arr;

        for (int i = 0; i < n; i++) {
            arr.push_back({digitSum(nums[i]), nums[i]});
        }

        sort(arr.begin(), arr.end());

        unordered_map<int, int> pos;

        for (int i = 0; i < n; i++) {
            pos[arr[i].second] = i;
        }

        vector<bool> visited(n, false);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i])
                continue;

            int j = i;
            int cnt = 0;

            while (!visited[j]) {
                visited[j] = true;
                j = pos[nums[j]];
                cnt++;
            }

            if (cnt > 1)
                ans += cnt - 1;
        }

        return ans;
    }
};
