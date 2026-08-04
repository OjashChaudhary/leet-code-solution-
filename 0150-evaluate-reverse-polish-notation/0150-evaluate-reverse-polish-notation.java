class Solution {
    public int evalRPN(String[] tokens) {
        int[] stack = new int[tokens.length];
        int top = -1;

        for (String s : tokens) {
            if (s.equals("+")) {
                stack[--top] = stack[top] + stack[top + 1];
            } else if (s.equals("-")) {
                stack[--top] = stack[top] - stack[top + 1];
            } else if (s.equals("*")) {
                stack[--top] = stack[top] * stack[top + 1];
            } else if (s.equals("/")) {
                stack[--top] = stack[top] / stack[top + 1];
            } else {
                stack[++top] = Integer.parseInt(s);
            }
        }

        return stack[top];
    }
}