class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        int n = nums.length;
        int[] ans = new int[n - k + 1];
        int[] dq = new int[n];
        int left = 0, right = 0;

        for (int i = 0; i < n; i++) {
            while (left < right && dq[left] <= i - k) {
                left++;
            }

            while (left < right && nums[dq[right - 1]] <= nums[i]) {
                right--;
            }

            dq[right++] = i;

            if (i >= k - 1) {
                ans[i - k + 1] = nums[dq[left]];
            }
        }

        return ans;
    }
}