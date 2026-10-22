class Solution {
public:
    bool solve(vector<int>&nums, int sum, int i){
        if(sum==0)return true;
        if(i>=nums.size())return false;
        if(sum - nums[i] >=0){
            return solve(nums,sum-nums[i],i+1);
        }

        return solve(nums,sum,i+1);
    }
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);

        if(sum%2)return false;

        sum/=2;


        return solve(nums,sum,0);

    }
};
