class Solution {
public:
    int n, m;
    vector<vector<vector<int>>> dp;

    bool solve(vector<vector<char>>& grid, int i, int j, int cnt) {
        if (i >= n || j >= m)
            return false;

        if (grid[i][j] == '(')
            cnt++;
        else
            cnt--;

        if (cnt < 0)
            return false;

        if (i == n - 1 && j == m - 1)
            return cnt == 0;

        if (dp[i][j][cnt] != -1)
            return dp[i][j][cnt];

        bool a = solve(grid, i + 1, j, cnt);
        bool b = solve(grid, i, j + 1, cnt);

        return dp[i][j][cnt] = (a || b);
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();

        if (grid[0][0] != '(' || grid[n - 1][m - 1] != ')')
            return false;

        dp.assign(n, vector<vector<int>>(m, vector<int>(n + m + 1, -1)));

        return solve(grid, 0, 0, 0);
    }
};