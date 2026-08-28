class Solution {
public:
    void solve(vector<int>&nums,vector<vector<int>>&ans,int i,vector<int>&res){
        if(i==nums.size()){
            ans.push_back(res) ;
            return ;
        } 

        // pick this element
        res.push_back(nums[i]);
        solve(nums,ans,i+1,res);


        // not picking this element
        res.pop_back();
        solve(nums,ans,i+1,res);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>res;
        solve(nums,ans,0,res);


        return ans;
    }
};
