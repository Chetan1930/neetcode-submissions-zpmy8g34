class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return backtrack(0, 0, nums, target);
    }
    unordered_map<string,int>mp;

    int backtrack(int i, int total, vector<int>& nums, int target) {
        if (i == nums.size()) {
            return total == target;
        }
        string temp = to_string(i);
        temp+="-";
        temp+=to_string(total);

        if(mp.count(temp))return mp[temp];


        return mp[temp] = backtrack(i + 1, total + nums[i], nums, target) +
               backtrack(i + 1, total - nums[i], nums, target);
    }
};