class MinStack {
    private int[] stack;
    private int[] min;
    private int top;

    public MinStack() {
        stack = new int[30000];
        min = new int[30000];
        top = -1;
    }

    public void push(int val) {
        top++;
        stack[top] = val;
        if (top == 0) {
            min[top] = val;
        } else {
            min[top] = Math.min(val, min[top - 1]);
        }
    }

    public void pop() {
        top--;
    }

    public int top() {
        return stack[top];
    }

    public int getMin() {
        return min[top];
    }
}