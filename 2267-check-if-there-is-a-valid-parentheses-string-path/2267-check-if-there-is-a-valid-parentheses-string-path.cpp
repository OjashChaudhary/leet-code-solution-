class Solution {
public:
    int n, m;
    vector<vector<vector<int>>> dp;

    bool dfs(vector<vector<char>>& grid, int i, int j, int cnt) {
        if (i >= n || j >= m)
            return false;

        if (grid[i][j] == '(')
            cnt++;
        else
            cnt--;

        if (cnt < 0)
            return false;

        int rem = (n - 1 - i) + (m - 1 - j);

        if (cnt > rem)
            return false;

        if (i == n - 1 && j == m - 1)
            return cnt == 0;

        if (dp[i][j][cnt] != -1)
            return dp[i][j][cnt];

        bool down = dfs(grid, i + 1, j, cnt);
        bool right = dfs(grid, i, j + 1, cnt);

        return dp[i][j][cnt] = down || right;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();

        if (grid[0][0] != '(' || grid[n - 1][m - 1] != ')')
            return false;

        if ((n + m - 1) % 2 != 0)
            return false;

        dp.assign(n, vector<vector<int>>(
            m, vector<int>(n + m + 1, -1)
        ));

        return dfs(grid, 0, 0, 0);
    }
};