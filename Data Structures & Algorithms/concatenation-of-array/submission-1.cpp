class Solution {
public:
    void concat(vector<int>&ans ,vector<int>&nums){
        for(auto &i:nums){
            ans.push_back(i);
        }
        return ;
    }
    vector<int> getConcatenation(vector<int>& nums) {
        
        vector<int>ans=nums;
        concat(ans,nums);

        return ans;
    }
};