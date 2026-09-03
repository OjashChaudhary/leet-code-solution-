class Solution {
public:
    int maxOr = 0;
    int count = 0;
    
    int countMaxOrSubsets(vector<int>& nums) {
        for (int num : nums) {
            maxOr |= num;
        }
        
        backtrack(nums, 0, 0);
        return count;
    }
    
    void backtrack(vector<int>& nums, int index, int currentOr) {
        if (index == nums.size()) {
            if (currentOr == maxOr) {
                count++;
            }
            return;
        }
        
        backtrack(nums, index + 1, currentOr | nums[index]);
        backtrack(nums, index + 1, currentOr);
    }
};