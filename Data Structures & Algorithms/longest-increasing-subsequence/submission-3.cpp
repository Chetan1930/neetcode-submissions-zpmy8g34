class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>lis;

        for(auto &i:nums){
            if(lis.size()==0)lis.emplace_back(i);
            else{
                int n=lis.size();
                if(i>lis[n-1]){
                    lis.emplace_back(i);
                }
                else{
                    auto idx = lower_bound(lis.begin(),lis.end(),i);
                    *idx = i;
                }
            }
        }


        return lis.size();
    }
};
