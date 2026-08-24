class Solution {
    public boolean isNStraightHand(int[] hand, int groupSize) {
        int n = hand.length;
        if (n % groupSize != 0) {
            return false;
        }
        
        TreeMap<Integer, Integer> count = new TreeMap<>();
        for (int card : hand) {
            count.put(card, count.getOrDefault(card, 0) + 1);
        }
        
        while (!count.isEmpty()) {
            int first = count.firstKey();
            int freq = count.get(first);
            
            for (int i = first; i < first + groupSize; i++) {
                if (!count.containsKey(i)) {
                    return false;
                }
                
                int newFreq = count.get(i) - freq;
                if (newFreq < 0) {
                    return false;
                } else if (newFreq == 0) {
                    count.remove(i);
                } else {
                    count.put(i, newFreq);
                }
            }
        }
        
        return true;
    }
}