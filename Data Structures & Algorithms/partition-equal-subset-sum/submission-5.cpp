class Solution {
public:
    unordered_map<int, bool> dp[201];

    bool solve(vector<int>& nums, int sum, int i) {
        if (sum == 0) return true;
        if (i >= nums.size() || sum < 0) return false;

        if (dp[i].count(sum)) {
            return dp[i][sum];
        }

        bool take = solve(nums, sum - nums[i], i + 1);
        bool skip = solve(nums, sum, i + 1);

        return dp[i][sum] = take || skip;
    }

    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum % 2 != 0) return false;

        return solve(nums, sum / 2, 0);
    }
};