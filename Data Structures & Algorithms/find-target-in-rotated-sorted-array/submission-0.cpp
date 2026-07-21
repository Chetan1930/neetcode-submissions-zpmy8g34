class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;

        while(l<=r){
            int mid=(r-l)/2 + l;

            if(nums[mid]==target)return mid;

            else if(nums[l]< nums[mid]){
                if(nums[l]<=target && nums[mid]>target){
                    r=mid-1;
                    
                }
                else{
                    l=mid+1;
                }
            }
            else if(nums[mid]< nums[r]){
                if(target>nums[mid] && target<=nums[r]){
                    l=mid+1;
                }
                else{
                    r=mid-1;
                }
            }
            else break;
        }

        return -1;
    }
};
