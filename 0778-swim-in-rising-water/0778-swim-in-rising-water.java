class Solution {
    public int swimInWater(int[][] grid) {
        int n = grid.length;
        boolean[][] visited = new boolean[n][n];
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        pq.offer(new int[]{grid[0][0], 0, 0});
        visited[0][0] = true;
        
        int[] dx = {1, -1, 0, 0};
        int[] dy = {0, 0, 1, -1};
        
        int result = 0;
        
        while (!pq.isEmpty()) {
            int[] current = pq.poll();
            int time = current[0];
            int row = current[1];
            int col = current[2];
            
            result = Math.max(result, time);
            
            if (row == n - 1 && col == n - 1) {
                return result;
            }
            
            for (int d = 0; d < 4; d++) {
                int newRow = row + dx[d];
                int newCol = col + dy[d];
                
                if (newRow < 0 || newRow >= n || newCol < 0 || newCol >= n) {
                    continue;
                }
                
                if (visited[newRow][newCol]) {
                    continue;
                }
                
                visited[newRow][newCol] = true;
                pq.offer(new int[]{grid[newRow][newCol], newRow, newCol});
            }
        }
        
        return result;
    }
}