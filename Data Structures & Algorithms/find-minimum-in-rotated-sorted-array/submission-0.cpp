class Solution {
public:
    int findMin(vector<int> &nums) {
        int s=0,e=nums.size()-1;
        int getmin=99999999;

        while(s<=e){
            int mid=(e-s)/2 + s;                                                        

            if(nums[mid]>nums[s]){
                getmin=min(getmin,nums[s]);
                s=mid+1;
            }
            else if(nums[mid]<nums[e]){
                getmin=min(nums[mid],getmin);
                e=mid-1;
            }
            else break;
        }

        return getmin;
    }
};
