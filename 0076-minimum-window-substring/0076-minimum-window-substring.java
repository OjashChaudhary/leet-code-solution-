class Solution {
    public String minWindow(String s, String t) {
        if (s.length() < t.length()) return "";

        int[] need = new int[128];
        for (char c : t.toCharArray()) {
            need[c]++;
        }

        int left = 0, count = t.length();
        int start = 0, len = Integer.MAX_VALUE;

        for (int right = 0; right < s.length(); right++) {
            char c = s.charAt(right);

            if (need[c] > 0) count--;
            need[c]--;

            while (count == 0) {
                if (right - left + 1 < len) {
                    len = right - left + 1;
                    start = left;
                }

                char x = s.charAt(left++);
                need[x]++;

                if (need[x] > 0) count++;
            }
        }

        return len == Integer.MAX_VALUE ? "" : s.substring(start, start + len);
    }
}