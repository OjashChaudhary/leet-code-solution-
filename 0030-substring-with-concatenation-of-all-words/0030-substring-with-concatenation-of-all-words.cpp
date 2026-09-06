class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        int n = s.length();
        int numWords = words.size();
        int wordLen = words[0].length();
        int totalLen = numWords * wordLen;
        
        if (n < totalLen) {
            return result;
        }
        
        unordered_map<string, int> wordCount;
        for (string& word : words) {
            wordCount[word]++;
        }
        
        for (int i = 0; i < wordLen; i++) {
            int left = i;
            int count = 0;
            unordered_map<string, int> windowCount;
            
            for (int j = i; j <= n - wordLen; j += wordLen) {
                string word = s.substr(j, wordLen);
                
                if (wordCount.find(word) != wordCount.end()) {
                    windowCount[word]++;
                    count++;
                    
                    while (windowCount[word] > wordCount[word]) {
                        string leftWord = s.substr(left, wordLen);
                        windowCount[leftWord]--;
                        left += wordLen;
                        count--;
                    }
                    
                    if (count == numWords) {
                        result.push_back(left);
                        string leftWord = s.substr(left, wordLen);
                        windowCount[leftWord]--;
                        left += wordLen;
                        count--;
                    }
                } else {
                    windowCount.clear();
                    count = 0;
                    left = j + wordLen;
                }
            }
        }
        
        return result;
    }
};