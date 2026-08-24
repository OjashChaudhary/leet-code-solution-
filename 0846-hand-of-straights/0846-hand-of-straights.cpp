class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0) {
            return false;
        }
        
        map<int, int> count;
        for (int card : hand) {
            count[card]++;
        }
        
        while (!count.empty()) {
            int first = count.begin()->first;
            int freq = count[first];
            
            for (int i = first; i < first + groupSize; i++) {
                if (count.find(i) == count.end()) {
                    return false;
                }
                
                count[i] -= freq;
                if (count[i] < 0) {
                    return false;
                } else if (count[i] == 0) {
                    count.erase(i);
                }
            }
        }
        
        return true;
    }
};