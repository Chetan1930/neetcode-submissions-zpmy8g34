class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0,j=nums.size()-1;

        vector<vector<int>>ans;

        while(i<j){
            int k=i+1;
            while(k<j){
                if(nums[i]+nums[k]+nums[j] == 0)ans.push_back({nums[i],nums[k],nums[j]});
                k++;
            }
            k--;
            if(nums[i]+nums[k]+nums[j] < 0)i++;
            else j--;            
        }

        return ans;

    }
};
