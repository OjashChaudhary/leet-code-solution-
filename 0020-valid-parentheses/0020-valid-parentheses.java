class Solution {
    public boolean isValid(String s) {
        char[] stack = new char[s.length()];
        int top = -1;

        for (char c : s.toCharArray()) {
            if (c == '(' || c == '{' || c == '[') {
                stack[++top] = c;
            } else {
                if (top < 0) return false;

                char x = stack[top--];

                if (c == ')' && x != '(') return false;
                if (c == '}' && x != '{') return false;
                if (c == ']' && x != '[') return false;
            }
        }

        return top == -1;
    }
}