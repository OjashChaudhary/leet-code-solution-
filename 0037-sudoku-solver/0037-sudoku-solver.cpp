class Solution {
public:
    bool row[9][10] = {};
    bool col[9][10] = {};
    bool box[9][10] = {};

    bool solve(vector<vector<char>>& board, int pos) {
        while (pos < 81 && board[pos / 9][pos % 9] != '.') {
            pos++;
        }

        if (pos == 81) {
            return true;
        }

        int r = pos / 9;
        int c = pos % 9;
        int b = (r / 3) * 3 + c / 3;

        for (int num = 1; num <= 9; num++) {
            if (row[r][num] || col[c][num] || box[b][num]) {
                continue;
            }

            board[r][c] = '0' + num;
            row[r][num] = true;
            col[c][num] = true;
            box[b][num] = true;

            if (solve(board, pos + 1)) {
                return true;
            }

            board[r][c] = '.';
            row[r][num] = false;
            col[c][num] = false;
            box[b][num] = false;
        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0';
                    int b = (i / 3) * 3 + j / 3;

                    row[i][num] = true;
                    col[j][num] = true;
                    box[b][num] = true;
                }
            }
        }

        solve(board, 0);
    }
};