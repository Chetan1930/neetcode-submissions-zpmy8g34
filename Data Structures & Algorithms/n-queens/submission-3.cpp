class Solution {
public:

    bool isSafe(vector<string>& board, int r, int c) {

        int n = board.size();

        // Same column
        for (int i = 0; i < r; i++) {
            if (board[i][c] == 'Q')
                return false;
        }

        // Upper-left diagonal
        for (int i = r - 1, j = c - 1;
             i >= 0 && j >= 0;
             i--, j--) {

            if (board[i][j] == 'Q')
                return false;
        }

        // Upper-right diagonal
        for (int i = r - 1, j = c + 1;
             i >= 0 && j < n;
             i--, j++) {

            if (board[i][j] == 'Q')
                return false;
        }

        return true;
    }

    void solve(vector<string>& board,
               vector<vector<string>>& ans,
               int r) {

        int n = board.size();

        // All queens placed
        if (r == n) {
            ans.push_back(board);
            return;
        }

        // Try every column in this row
        for (int c = 0; c < n; c++) {

            if (isSafe(board, r, c)) {

                // Choose
                board[r][c] = 'Q';

                // Explore
                solve(board, ans, r + 1);

                // Backtrack
                board[r][c] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> ans;

        vector<string> board(n, string(n, '.'));

        solve(board, ans, 0);

        return ans;
    }
};