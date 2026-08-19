class Solution {
    public int rob(int[] nums) {
        int n = nums.length;
        if (n == 1) {
            return nums[0];
        }
        
        int[] first = new int[n - 1];
        int[] second = new int[n - 1];
        
        for (int i = 0; i < n - 1; i++) {
            first[i] = nums[i];
        }
        
        for (int i = 1; i < n; i++) {
            second[i - 1] = nums[i];
        }
        
        return Math.max(robLine(first), robLine(second));
    }
    
    private int robLine(int[] nums) {
        int prev2 = 0;
        int prev1 = 0;
        
        for (int i = 0; i < nums.length; i++) {
            int current = Math.max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = current;
        }
        
        return prev1;
    }
}