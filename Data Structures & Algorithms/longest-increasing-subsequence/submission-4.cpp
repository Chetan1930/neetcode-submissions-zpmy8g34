class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>lis;

        for(auto &i:nums){
            auto idx = lower_bound(lis.begin(),lis.end(),i);
            
            if(idx==lis.end())lis.emplace_back(i);
            else *idx = i;
        }


        return lis.size();
    }
};
