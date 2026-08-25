class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int x = 0, y = 0, z = 0;
        
        for (auto& triplet : triplets) {
            if (triplet[0] <= target[0] && triplet[1] <= target[1] && triplet[2] <= target[2]) {
                x = max(x, triplet[0]);
                y = max(y, triplet[1]);
                z = max(z, triplet[2]);
            }
        }
        
        return x == target[0] && y == target[1] && z == target[2];
    }
};