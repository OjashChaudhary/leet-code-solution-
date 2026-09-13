class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> roots(dictionary.begin(), dictionary.end());
        stringstream ss(sentence);
        string word, ans;

        while (ss >> word) {
            string prefix = "";

            for (int i = 0; i < word.size(); i++) {
                prefix += word[i];

                if (roots.count(prefix)) {
                    word = prefix;
                    break;
                }
            }

            if (!ans.empty())
                ans += " ";

            ans += word;
        }

        return ans;
    }
};