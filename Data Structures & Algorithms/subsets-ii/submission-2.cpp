class Solution {
public:
    void solve(vector<int>&nums, vector<int>&ans, vector<vector<int>>&res,int i){
        res.push_back(ans);
       


        for(int j=i;j<nums.size();j++){
           if(j > i && nums[j] == nums[j-1])
    continue;

            ans.push_back(nums[j]);
            solve(nums,ans,res,j+1);
            ans.pop_back();
        }
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>ans;
        vector<vector<int>>res;

        sort(nums.begin(),nums.end());

        solve(nums,ans,res,0);

        return res;
    }
};
