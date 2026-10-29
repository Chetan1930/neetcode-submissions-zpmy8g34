class Solution {
public:
    int n, m;

    int dfs(vector<vector<int>>& matrix,
            vector<vector<int>>& dp, int i, int j) {

        if (dp[i][j] != 0)
            return dp[i][j];

        int best = 1;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int d = 0; d < 4; d++) {
            int r = i + dr[d];
            int c = j + dc[d];

            if (r >= 0 && r < n && c >= 0 && c < m &&
                matrix[r][c] > matrix[i][j]) {

                best = max(best, 1 + dfs(matrix, dp, r, c));
            }
        }

        return dp[i][j] = best;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m, 0));

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans = max(ans, dfs(matrix, dp, i, j));
            }
        }

        return ans;
    }
};