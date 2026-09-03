class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> changes(1001, 0);
        
        for (auto& trip : trips) {
            int numPassengers = trip[0];
            int from = trip[1];
            int to = trip[2];
            
            changes[from] += numPassengers;
            changes[to] -= numPassengers;
        }
        
        int currentPassengers = 0;
        
        for (int i = 0; i < 1001; i++) {
            currentPassengers += changes[i];
            
            if (currentPassengers > capacity) {
                return false;
            }
        }
        
        return true;
    }
};