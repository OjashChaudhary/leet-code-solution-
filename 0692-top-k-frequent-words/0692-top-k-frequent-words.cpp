class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> count;
        
        for (string& word : words) {
            count[word]++;
        }
        
        auto cmp = [](pair<string,int>& a, pair<string,int>& b) {
            if (a.second != b.second) {
                return a.second > b.second;
            }
            return a.first < b.first;
        };
        
        vector<pair<string,int>> freqList(count.begin(), count.end());
        sort(freqList.begin(), freqList.end(), cmp);
        
        vector<string> result;
        for (int i = 0; i < k; i++) {
            result.push_back(freqList[i].first);
        }
        
        return result;
    }
};