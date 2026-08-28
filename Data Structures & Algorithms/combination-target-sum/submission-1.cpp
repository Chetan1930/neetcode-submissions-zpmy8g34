class Solution {
public:
    void solve(vector<int>& nums, int target,vector<vector<int>>&res,vector<int>&ans,int sum,int i){
        if(sum==target ){
            res.push_back(ans);
            return;
        }
        if(sum>target || i>=nums.size()){
            return ;
        }

        //pick this numer and try again with the same number
        ans.push_back(nums[i]);
        sum=sum+nums[i];
        solve(nums,target,res,ans,sum,i);



        // skip this number 
        ans.pop_back();
        sum=sum-nums[i];
        solve(nums,target,res,ans,sum,i+1);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>res;
        vector<int>ans;

        solve(nums,target,res,ans,0,0);
        return res;
    }
};
