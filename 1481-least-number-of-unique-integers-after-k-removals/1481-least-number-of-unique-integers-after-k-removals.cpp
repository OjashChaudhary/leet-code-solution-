class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> count;
        
        for (int num : arr) {
            count[num]++;
        }
        
        vector<int> freqList;
        for (auto& entry : count) {
            freqList.push_back(entry.second);
        }
        
        sort(freqList.begin(), freqList.end());
        
        int uniqueCount = freqList.size();
        
        for (int freq : freqList) {
            if (k >= freq) {
                k -= freq;
                uniqueCount--;
            } else {
                break;
            }
        }
        
        return uniqueCount;
    }
};