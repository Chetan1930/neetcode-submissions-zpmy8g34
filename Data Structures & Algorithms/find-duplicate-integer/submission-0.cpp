class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        vector<int>v(n+1,0);

        for(auto &i:nums){
            if(v[i]==1)return i;
            else v[i]++;
        }

        return -1;
    }
};
