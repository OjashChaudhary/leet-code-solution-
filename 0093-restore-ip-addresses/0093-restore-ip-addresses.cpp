class Solution {
public:
    vector<string> ans;

    void backtrack(string &s, int index, int count, string ip) {
        if (count == 4) {
            if (index == s.size()) {
                ip.pop_back();
                ans.push_back(ip);
            }
            return;
        }

        int num = 0;

        for (int i = index; i < s.size() && i < index + 3; i++) {
            if (i > index && s[index] == '0') {
                break;
            }

            num = num * 10 + (s[i] - '0');

            if (num > 255) {
                break;
            }

            string part = s.substr(index, i - index + 1);

            backtrack(s, i + 1, count + 1, ip + part + ".");
        }
    }

    vector<string> restoreIpAddresses(string s) {
        ans.clear();

        if (s.size() < 4 || s.size() > 12) {
            return ans;
        }

        backtrack(s, 0, 0, "");

        return ans;
    }
};