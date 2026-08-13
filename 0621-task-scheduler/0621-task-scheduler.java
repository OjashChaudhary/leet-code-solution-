import java.util.*;

class Solution {
    public int leastInterval(char[] tasks, int n) {
        int[] count = new int[26];

        for (char c : tasks) {
            count[c - 'A']++;
        }

        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());

        for (int x : count) {
            if (x > 0) {
                pq.add(x);
            }
        }

        int time = 0;

        while (!pq.isEmpty()) {
            int cycle = n + 1;
            int done = 0;
            int[] temp = new int[26];

            while (cycle > 0 && !pq.isEmpty()) {
                int x = pq.poll();
                x--;
                if (x > 0) {
                    temp[done++] = x;
                }
                cycle--;
                time++;
            }

            for (int i = 0; i < done; i++) {
                pq.add(temp[i]);
            }

            if (pq.isEmpty()) {
                break;
            }

            time += cycle;
        }

        return time;
    }
}