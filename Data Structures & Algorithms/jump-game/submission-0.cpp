class Solution {
public:
    bool solve(vector<int>& nums, int i) {
        if(i == nums.size() - 1) return true;

        if(i >= nums.size()) return false;

        for(int j = i + 1; j <= i + nums[i]; j++) {
            if(solve(nums, j)) {
                return true;
            }
        }

        return false;
    }

    bool canJump(vector<int>& nums) {
        return solve(nums, 0);
    }
};