class Solution {
public:
    set<string> solve(string s, int &i) {
        set<string> ans;
        set<string> cur = {""};

        while (i < s.size() && s[i] != '}') {

            if (s[i] == '{') {
                i++;

                set<string> temp = solve(s, i);
                i++;

                set<string> next;

                for (string a : cur) {
                    for (string b : temp) {
                        next.insert(a + b);
                    }
                }

                cur = next;
            }

            else if (s[i] == ',') {
                for (string x : cur)
                    ans.insert(x);

                cur = {""};
                i++;
            }

            else {
                set<string> next;

                for (string x : cur) {
                    next.insert(x + s[i]);
                }

                cur = next;
                i++;
            }
        }

        for (string x : cur)
            ans.insert(x);

        return ans;
    }

    vector<string> braceExpansionII(string expression) {
        int i = 0;

        set<string> st = solve(expression, i);

        return vector<string>(st.begin(), st.end());
    }
};