class Solution {
public:

    void waytoA(vector<vector<int>>& heights,
                vector<vector<int>>& A,
                int r, int c) {

        int n = heights.size();
        int m = heights[0].size();

        // Already visited
        if(A[r][c])
            return;

        A[r][c] = 1;

        // Move UP
        if(r > 0 && heights[r-1][c] >= heights[r][c]) {
            waytoA(heights, A, r-1, c);
        }

        // Move DOWN
        if(r < n-1 && heights[r+1][c] >= heights[r][c]) {
            waytoA(heights, A, r+1, c);
        }

        // Move LEFT
        if(c > 0 && heights[r][c-1] >= heights[r][c]) {
            waytoA(heights, A, r, c-1);
        }

        // Move RIGHT
        if(c < m-1 && heights[r][c+1] >= heights[r][c]) {
            waytoA(heights, A, r, c+1);
        }
    }


    void waytoP(vector<vector<int>>& heights,
                vector<vector<int>>& P,
                int r, int c) {

        int n = heights.size();
        int m = heights[0].size();

        if(P[r][c])
            return;

        P[r][c] = 1;

        // UP
        if(r > 0 && heights[r-1][c] >= heights[r][c]) {
            waytoP(heights, P, r-1, c);
        }

        // DOWN
        if(r < n-1 && heights[r+1][c] >= heights[r][c]) {
            waytoP(heights, P, r+1, c);
        }

        // LEFT
        if(c > 0 && heights[r][c-1] >= heights[r][c]) {
            waytoP(heights, P, r, c-1);
        }

        // RIGHT
        if(c < m-1 && heights[r][c+1] >= heights[r][c]) {
            waytoP(heights, P, r, c+1);
        }
    }


    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> P(n, vector<int>(m, 0));
        vector<vector<int>> A(n, vector<int>(m, 0));

        vector<vector<int>> ans;


        // Pacific:
        // Top row
        for(int j = 0; j < m; j++) {
            waytoP(heights, P, 0, j);
        }

        // Left column
        for(int i = 0; i < n; i++) {
            waytoP(heights, P, i, 0);
        }


        // Atlantic:
        // Bottom row
        for(int j = 0; j < m; j++) {
            waytoA(heights, A, n-1, j);
        }

        // Right column
        for(int i = 0; i < n; i++) {
            waytoA(heights, A, i, m-1);
        }


        // Common cells
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(P[i][j] && A[i][j]) {
                    ans.push_back({i, j});
                }

            }
        }

        return ans;
    }
};