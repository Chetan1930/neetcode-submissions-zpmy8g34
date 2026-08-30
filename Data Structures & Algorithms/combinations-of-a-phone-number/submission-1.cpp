class Solution {
public:

    void solve(string& digits,
               unordered_map<int, vector<char>>& mp,
               int i,
               vector<string>& res,
               string& ans) {

        if (i == digits.length()) {
            res.push_back(ans);
            return;
        }

        int temp = digits[i] - '0';

        vector<char>& rch = mp[temp];

        for (int k = 0; k < rch.size(); k++) {

            ans.push_back(rch[k]);

            solve(digits, mp, i + 1, res, ans);

            ans.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {

        if (digits.empty())
            return {};

        unordered_map<int, vector<char>> mp;

        mp[2] = {'a', 'b', 'c'};
        mp[3] = {'d', 'e', 'f'};
        mp[4] = {'g', 'h', 'i'};
        mp[5] = {'j', 'k', 'l'};
        mp[6] = {'m', 'n', 'o'};
        mp[7] = {'p', 'q', 'r', 's'};
        mp[8] = {'t', 'u', 'v'};
        mp[9] = {'w', 'x', 'y', 'z'};

        vector<string> res;
        string ans = "";

        solve(digits, mp, 0, res, ans);

        return res;
    }
};