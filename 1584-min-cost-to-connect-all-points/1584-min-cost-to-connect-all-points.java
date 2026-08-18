class Solution {
    public int minCostConnectPoints(int[][] points) {
        int n = points.length;
        boolean[] visited = new boolean[n];
        int[] minDist = new int[n];
        Arrays.fill(minDist, Integer.MAX_VALUE);
        minDist[0] = 0;
        
        int totalCost = 0;
        
        for (int i = 0; i < n; i++) {
            int current = -1;
            
            for (int j = 0; j < n; j++) {
                if (!visited[j] && (current == -1 || minDist[j] < minDist[current])) {
                    current = j;
                }
            }
            
            visited[current] = true;
            totalCost += minDist[current];
            
            for (int next = 0; next < n; next++) {
                if (!visited[next]) {
                    int dist = Math.abs(points[current][0] - points[next][0]) + Math.abs(points[current][1] - points[next][1]);
                    
                    if (dist < minDist[next]) {
                        minDist[next] = dist;
                    }
                }
            }
        }
        
        return totalCost;
    }
}