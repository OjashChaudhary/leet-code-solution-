class Solution {
public:
    int hammingDistance(int x, int y) {
        int xorResult = x ^ y;
        int count = 0;
        
        while (xorResult != 0) {
            xorResult = xorResult & (xorResult - 1);
            count++;
        }
        
        return count;
    }
};