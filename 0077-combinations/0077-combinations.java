class Solution {
    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> result = new ArrayList<>();
        int[] temp = new int[k];
        int i = 0;
        
        while (i >= 0) {
            temp[i]++;
            
            if (temp[i] > n) {
                i--;
            } else if (i == k - 1) {
                List<Integer> combination = new ArrayList<>();
                for (int num : temp) {
                    combination.add(num);
                }
                result.add(combination);
            } else {
                i++;
                temp[i] = temp[i - 1];
            }
        }
        
        return result;
    }
}