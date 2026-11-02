class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxJ=0;
        int n=nums.size();
        for(int i=0;i<n;i++){

            if(i>maxJ)return false;


            maxJ = max(maxJ,i + nums[i]);


            if(maxJ >= n  -1 )return true;

        }


        return false;
    }
};
