class Solution {
    public int findLeastNumOfUniqueInts(int[] arr, int k) {
        Map<Integer, Integer> count = new HashMap<>();
        
        for (int num : arr) {
            count.put(num, count.getOrDefault(num, 0) + 1);
        }
        
        List<Integer> freqList = new ArrayList<>(count.values());
        Collections.sort(freqList);
        
        int uniqueCount = freqList.size();
        
        for (int freq : freqList) {
            if (k >= freq) {
                k -= freq;
                uniqueCount--;
            } else {
                break;
            }
        }
        
        return uniqueCount;
    }
}