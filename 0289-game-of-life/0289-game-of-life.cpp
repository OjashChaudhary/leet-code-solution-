class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int liveNeighbors = countLiveNeighbors(board, i, j, rows, cols);
                
                if (board[i][j] == 1) {
                    if (liveNeighbors < 2 || liveNeighbors > 3) {
                        board[i][j] = 2;
                    }
                } else {
                    if (liveNeighbors == 3) {
                        board[i][j] = 3;
                    }
                }
            }
        }
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == 2) {
                    board[i][j] = 0;
                } else if (board[i][j] == 3) {
                    board[i][j] = 1;
                }
            }
        }
    }
    
    int countLiveNeighbors(vector<vector<int>>& board, int row, int col, int rows, int cols) {
        int count = 0;
        
        for (int di = -1; di <= 1; di++) {
            for (int dj = -1; dj <= 1; dj++) {
                if (di == 0 && dj == 0) {
                    continue;
                }
                
                int newRow = row + di;
                int newCol = col + dj;
                
                if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols) {
                    if (board[newRow][newCol] == 1 || board[newRow][newCol] == 2) {
                        count++;
                    }
                }
            }
        }
        
        return count;
    }
};