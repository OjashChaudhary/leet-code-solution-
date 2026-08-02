class Solution {
    public boolean checkInclusion(String s1, String s2) {
        if (s1.length() > s2.length()) return false;

        int[] a = new int[26];
        int[] b = new int[26];

        for (int i = 0; i < s1.length(); i++) {
            a[s1.charAt(i) - 'a']++;
            b[s2.charAt(i) - 'a']++;
        }

        for (int i = s1.length(); i < s2.length(); i++) {
            if (java.util.Arrays.equals(a, b)) return true;

            b[s2.charAt(i) - 'a']++;
            b[s2.charAt(i - s1.length()) - 'a']--;
        }

        return java.util.Arrays.equals(a, b);
    }
}