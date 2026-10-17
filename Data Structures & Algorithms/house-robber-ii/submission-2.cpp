class Solution {
public:
    int solve(vector<int>& nums, int i, vector<int>& dp) {
        if (i >= nums.size()) return 0;

        if (dp[i] != -1) return dp[i];

        return dp[i] = max(
            nums[i] + solve(nums, i + 2, dp),
            solve(nums, i + 1, dp)
        );
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return nums[0];

        vector<int> arr1(nums.begin(), nums.end() - 1);
        vector<int> arr2(nums.begin() + 1, nums.end());

        vector<int> dp1(arr1.size(), -1);
        vector<int> dp2(arr2.size(), -1);

        return max(
            solve(arr1, 0, dp1),
            solve(arr2, 0, dp2)
        );
    }
};