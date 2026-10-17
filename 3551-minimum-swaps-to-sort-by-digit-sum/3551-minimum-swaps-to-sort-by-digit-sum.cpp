
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
        vector<array<int, 2>> arr(n);

        for (int i = 0; i < n; i++) {
            arr[i] = {digitSum(nums[i]), i};
        }

        sort(arr.begin(), arr.end(), [&](auto &a, auto &b) {
            if (a[0] != b[0])
                return a[0] < b[0];

            return nums[a[1]] < nums[b[1]];
        });

        vector<bool> visited(n, false);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i] || arr[i][1] == i)
                continue;

            int j = i;
            int cnt = 0;

            while (!visited[j]) {
                visited[j] = true;
                j = arr[j][1];
                cnt++;
            }

            ans += cnt - 1;
        }

        return ans;
    }
};
