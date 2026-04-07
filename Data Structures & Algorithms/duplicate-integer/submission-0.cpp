class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto &i:nums){
            if(mp.find(i)==mp.end())mp[i]++;
            else return true;
        }
        return false;
    }
};