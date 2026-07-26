class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Case 1:  this will check whether every row is valid or not
        for (int i = 0; i < 9; i++) {
            unordered_map<char, int> mp;
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    mp[board[i][j]]++;
                }
            }
            for (auto& k : mp)
                if (k.second > 1) return false;
        }

        // Case 2:  this will check whether every Column is valid or not
        for (int i = 0; i < 9; i++) {
            unordered_map<char, int> mp;
            for (int j = 0; j < 9; j++) {
                if (board[j][i] != '.') {
                    mp[board[j][i]]++;
                }
            }
            for (auto& k : mp)
                if (k.second > 1) return false;
        }

        // Case 3: now let's check for the square as well
        for (int r = 0; r < 9; r += 3) {
            for (int c = 0; c < 9; c += 3) {
                unordered_map<char, int> mp;
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        char val = board[r + i][c + j];
                        if (val != '.') mp[val]++;
                    }
                }
                for (auto& k : mp)
                    if (k.second > 1) return false;
            }
        }

        return true;
    }
};