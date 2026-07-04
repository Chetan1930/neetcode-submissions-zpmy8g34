class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        unordered_map<int,int>mp;

        for(int i=0;i<nums.size();i++)mp[nums[i]]++;

        vector<pair<int,int>>sortedv;

        for(auto &i:mp)sortedv.push_back({i.second,i.first});



        sort(sortedv.begin(),sortedv.end());

        // for(auto &i:sortedv)cout<<i.first<<" "<<i.second<<endl;

        for(int i = sortedv.size()-1 ;i>=0 && k>0;i--){
            ans.push_back(sortedv[i].second);
            k--;
        }

        return ans;
    }
};
