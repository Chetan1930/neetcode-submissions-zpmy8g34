class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool>pick(nums.size(),0);

        vector<vector<int>>res;
        vector<int>ans;

        solve(nums,res,ans, pick);

        return res;
    }

    void solve(vector<int>&nums, vector<vector<int>>&res,vector<int>&ans, vector<bool>&pick){
        if(ans.size()==nums.size()){
            res.push_back(ans);
        }

        for(int i=0;i<nums.size();i++){

            if(!pick[i]){
                ans.push_back(nums[i]);
                pick[i]=true;
                solve(nums,res,ans,pick);
                pick[i]=false;
                ans.pop_back();
            }

        }
    }
};
