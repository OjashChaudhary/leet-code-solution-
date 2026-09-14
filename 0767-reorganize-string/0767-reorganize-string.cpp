class Solution {
public:
    string reorganizeString(string s) {
        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        int maxFreq = 0;
        int maxChar = 0;

        for (int i = 0; i < 26; i++) {
            if (freq[i] > maxFreq) {
                maxFreq = freq[i];
                maxChar = i;
            }
        }

        if (maxFreq > (s.size() + 1) / 2)
            return "";

        string ans(s.size(), ' ');
        int index = 0;

        while (freq[maxChar] > 0) {
            ans[index] = char('a' + maxChar);
            index += 2;
            freq[maxChar]--;
        }

        for (int i = 0; i < 26; i++) {
            while (freq[i] > 0) {
                if (index >= s.size())
                    index = 1;

                ans[index] = char('a' + i);
                index += 2;
                freq[i]--;
            }
        }

        return ans;
    }
};