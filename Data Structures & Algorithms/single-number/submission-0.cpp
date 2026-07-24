class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int temp=0;

        for(auto &i:nums)temp=temp^i;

        return temp;
    }
};
