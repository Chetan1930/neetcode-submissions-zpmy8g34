class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0,r=nums.size()-1;

        while(l<r){
            int m= ( r-l)/2 + l;

            if(nums[r]>nums[m]){
                r=m;
            }
            else l=m+1;
        }

        return nums[l];
    }
};