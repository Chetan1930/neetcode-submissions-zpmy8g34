class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxp=nums[0];
        int minp=nums[0];
        int curr = nums[0];

        int ans =nums[0];
        for(int i=1;i<nums.size();i++){
            curr = curr*nums[i];
            maxp = max(maxp, curr);
            minp = min(minp,curr);

            ans = max(ans,max(maxp,nums[i]));
        }
        

        return ans;
    }
};
