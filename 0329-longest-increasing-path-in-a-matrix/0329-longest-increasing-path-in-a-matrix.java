class Solution {
    public int longestIncreasingPath(int[][] matrix) {
        int rows = matrix.length;
        int cols = matrix[0].length;
        int[][] memo = new int[rows][cols];
        int maxLen = 0;
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                maxLen = Math.max(maxLen, dfs(matrix, i, j, memo));
            }
        }
        
        return maxLen;
    }
    
    private int dfs(int[][] matrix, int row, int col, int[][] memo) {
        if (memo[row][col] != 0) {
            return memo[row][col];
        }
        
        int[] dx = {1, -1, 0, 0};
        int[] dy = {0, 0, 1, -1};
        int best = 1;
        
        for (int d = 0; d < 4; d++) {
            int newRow = row + dx[d];
            int newCol = col + dy[d];
            
            if (newRow < 0 || newRow >= matrix.length || newCol < 0 || newCol >= matrix[0].length) {
                continue;
            }
            
            if (matrix[newRow][newCol] <= matrix[row][col]) {
                continue;
            }
            
            best = Math.max(best, 1 + dfs(matrix, newRow, newCol, memo));
        }
        
        memo[row][col] = best;
        return best;
    }
}