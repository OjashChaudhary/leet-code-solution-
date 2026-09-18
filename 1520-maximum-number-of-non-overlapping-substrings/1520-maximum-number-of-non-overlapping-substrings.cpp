
class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<int> first(26, -1), last(26, -1);

        for (int i = 0; i < s.size(); i++) {
            int x = s[i] - 'a';

            if (first[x] == -1)
                first[x] = i;

            last[x] = i;
        }

        vector<pair<int, int>> ranges;

        for (int i = 0; i < 26; i++) {
            if (first[i] == -1)
                continue;

            int l = first[i];
            int r = last[i];
            bool valid = true;

            for (int j = l; j <= r; j++) {
                int x = s[j] - 'a';

                if (first[x] < l) {
                    valid = false;
                    break;
                }

                r = max(r, last[x]);
            }

            if (valid)
                ranges.push_back({l, r});
        }

        sort(ranges.begin(), ranges.end(),
             [](pair<int, int>& a, pair<int, int>& b) {
                 return a.second < b.second;
             });

        vector<string> ans;
        int end = -1;

        for (auto p : ranges) {
            if (p.first > end) {
                ans.push_back(s.substr(p.first, p.second - p.first + 1));
                end = p.second;
            }
        }

        return ans;
    }
};