class Solution {
public:
    void dfs(vector<vector<int>>& grid, int r, int c) {
        int n = grid.size();
        int m = grid[0].size();

        if (r < 0 || r >= n || c < 0 || c >= m)
            return;

        if (grid[r][c] == -1)
            return;

        if (r > 0 && grid[r-1][c] > grid[r][c] + 1) {
            grid[r-1][c] = grid[r][c] + 1;
            dfs(grid, r-1, c);
        }

        if (r + 1 < n && grid[r+1][c] > grid[r][c] + 1) {
            grid[r+1][c] = grid[r][c] + 1;
            dfs(grid, r+1, c);
        }

        if (c > 0 && grid[r][c-1] > grid[r][c] + 1) {
            grid[r][c-1] = grid[r][c] + 1;
            dfs(grid, r, c-1);
        }

        if (c + 1 < m && grid[r][c+1] > grid[r][c] + 1) {
            grid[r][c+1] = grid[r][c] + 1;
            dfs(grid, r, c+1);
        }
    }

    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    dfs(grid, i, j);
                }
            }
        }
    }
};