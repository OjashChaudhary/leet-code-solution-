import java.util.*;

class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {

        HashMap<String, List<String>> map = new HashMap<>();

        for (String word : strs) {

            int[] count = new int[26];

            for (int i = 0; i < word.length(); i++) {
                count[word.charAt(i) - 'a']++;
            }

            StringBuilder key = new StringBuilder();

            for (int i = 0; i < 26; i++) {
                key.append('#');
                key.append(count[i]);
            }

            String finalKey = key.toString();

            if (!map.containsKey(finalKey)) {
                map.put(finalKey, new ArrayList<>());
            }

            map.get(finalKey).add(word);
        }

        return new ArrayList<>(map.values());
    }
}