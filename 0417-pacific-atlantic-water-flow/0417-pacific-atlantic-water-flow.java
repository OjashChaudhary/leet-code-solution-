class Solution {
    public List<List<Integer>> pacificAtlantic(int[][] heights) {
        List<List<Integer>> result = new ArrayList<>();
        int rows = heights.length;
        int cols = heights[0].length;
        
        boolean[][] pacific = new boolean[rows][cols];
        boolean[][] atlantic = new boolean[rows][cols];
        
        for (int i = 0; i < rows; i++) {
            dfs(heights, pacific, i, 0);
            dfs(heights, atlantic, i, cols - 1);
        }
        
        for (int j = 0; j < cols; j++) {
            dfs(heights, pacific, 0, j);
            dfs(heights, atlantic, rows - 1, j);
        }
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.add(Arrays.asList(i, j));
                }
            }
        }
        
        return result;
    }
    
    private void dfs(int[][] heights, boolean[][] visited, int row, int col) {
        visited[row][col] = true;
        
        int[] dx = {1, -1, 0, 0};
        int[] dy = {0, 0, 1, -1};
        
        for (int d = 0; d < 4; d++) {
            int newRow = row + dx[d];
            int newCol = col + dy[d];
            
            if (newRow < 0 || newRow >= heights.length || newCol < 0 || newCol >= heights[0].length) {
                continue;
            }
            
            if (visited[newRow][newCol]) {
                continue;
            }
            
            if (heights[newRow][newCol] < heights[row][col]) {
                continue;
            }
            
            dfs(heights, visited, newRow, newCol);
        }
    }
}