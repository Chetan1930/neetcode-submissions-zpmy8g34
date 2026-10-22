class Solution {
public:
    bool ans = false;
    void solve(vector<int>&nums, int sum, int i){
        if(sum==0){
            ans = true;
            return;
        }
        if(i>=nums.size())return ;

        if(sum - nums[i] >=0)solve(nums,sum-nums[i],i+1);
        

        solve(nums,sum,i+1);
    }
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);

        if(sum%2)return false;

        sum/=2;


        solve(nums,sum,0);

        return ans;

    }
};
