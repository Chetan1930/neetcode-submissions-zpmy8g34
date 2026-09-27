class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {

        int n = grid.size();

        // {maximum height encountered, row, column}
        priority_queue<
            tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            greater<tuple<int, int, int>>
        > pq;

        vector<vector<int>> vis(n, vector<int>(n, 0));

        pq.push({grid[0][0], 0, 0});

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!pq.empty()) {

            auto [cost, r, c] = pq.top();
            pq.pop();

            if (vis[r][c])
                continue;

            vis[r][c] = 1;

            // Reached destination
            if (r == n - 1 && c == n - 1)
                return cost;

            for (int k = 0; k < 4; k++) {

                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr < 0 || nr >= n ||
                    nc < 0 || nc >= n)
                    continue;

                if (vis[nr][nc])
                    continue;

                // Cost of this path is the maximum
                // height encountered so far
                int newCost = max(cost, grid[nr][nc]);

                pq.push({newCost, nr, nc});
            }
        }

        return -1;
    }
};