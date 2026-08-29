class Solution {
public:
    bool ispal(string &s) {
        int i = 0;
        int j = s.length() - 1;

        while (i < j) {
            if (s[i] != s[j])
                return false;

            i++;
            j--;
        }

        return true;
    }

    void solve(string &s, vector<vector<string>>& res,
               vector<string>& ans, int i) {

        if (i >= s.length()) {
            res.push_back(ans);
            return;
        }

        for (int j = i; j < s.length(); j++) {

            string temp = s.substr(i, j - i + 1);

            if (ispal(temp)) {

                ans.push_back(temp);

                solve(s, res, ans, j + 1);

                ans.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> ans;

        solve(s, res, ans, 0);

        return res;
    }
};