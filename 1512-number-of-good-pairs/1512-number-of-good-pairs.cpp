class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int count[101] = {0};
        int pairs = 0;
        
        for (int num : nums) {
            pairs += count[num];
            count[num]++;
        }
        
        return pairs;
    }
};