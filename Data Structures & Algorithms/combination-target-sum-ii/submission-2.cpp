class Solution {
public:

    void solve(vector<int>& v,vector<vector<int>>& res,vector<int>& ans,int target,int i) {

        if (target == 0) {
            res.push_back(ans);
            return;
        }

        for (int j = i; j < v.size(); j++) {

            // Skip duplicate choices at the SAME recursion level
            if (j > i && v[j] == v[j - 1])
                continue;

            // Since sorted, nothing after this can work
            if (v[j] > target)
                break;

            ans.push_back(v[j]);

            solve(v, res, ans, target - v[j], j + 1);

            ans.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates,
                                        int target) {

        sort(candidates.begin(), candidates.end());

        vector<vector<int>> res;
        vector<int> ans;

        solve(candidates, res, ans, target, 0);

        return res;
    }
};