class Solution {
public:
    string removeKdigits(string num, int k) {
        deque<char> stack;
        
        for (char c : num) {
            while (!stack.empty() && k > 0 && stack.back() > c) {
                stack.pop_back();
                k--;
            }
            stack.push_back(c);
        }
        
        while (k > 0) {
            stack.pop_back();
            k--;
        }
        
        string result = "";
        for (char c : stack) {
            result += c;
        }
        
        int i = 0;
        while (i < result.length() - 1 && result[i] == '0') {
            i++;
        }
        
        result = result.substr(i);
        
        return result.empty() ? "0" : result;
    }
};