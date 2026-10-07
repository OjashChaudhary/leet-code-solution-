class Solution {
public:
    bool valid(string s) {
        int cnt = 0;

        for (char c : s) {
            if (c == '(')
                cnt++;
            else if (c == ')') {
                cnt--;

                if (cnt < 0)
                    return false;
            }
        }

        return cnt == 0;
    }

    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        unordered_set<string> visited;
        queue<string> q;

        q.push(s);
        visited.insert(s);

        bool found = false;

        while (!q.empty() && !found) {
            int size = q.size();

            while (size--) {
                string cur = q.front();
                q.pop();

                if (valid(cur)) {
                    ans.push_back(cur);
                    found = true;
                }

                if (found)
                    continue;

                for (int i = 0; i < cur.size(); i++) {
                    if (cur[i] != '(' && cur[i] != ')')
                        continue;

                    string next = cur.substr(0, i) + cur.substr(i + 1);

                    if (visited.find(next) == visited.end()) {
                        visited.insert(next);
                        q.push(next);
                    }
                }
            }
        }

        return ans;
    }
};