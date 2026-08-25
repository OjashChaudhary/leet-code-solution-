class Solution {
    public boolean mergeTriplets(int[][] triplets, int[] target) {
        int x = 0, y = 0, z = 0;
        
        for (int[] triplet : triplets) {
            if (triplet[0] <= target[0] && triplet[1] <= target[1] && triplet[2] <= target[2]) {
                x = Math.max(x, triplet[0]);
                y = Math.max(y, triplet[1]);
                z = Math.max(z, triplet[2]);
            }
        }
        
        return x == target[0] && y == target[1] && z == target[2];
    }
}