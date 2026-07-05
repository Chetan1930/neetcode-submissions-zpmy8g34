class Solution {
public:
   
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int>mp;

        for(auto &i:nums){
            mp[i]++;
        }

        int ans=0;
        for(auto &i:nums){
            if (mp.count(i - 1)) continue;

            int temp =1;
            //check forward
            int search=i;
            while(mp.count(search+1)){
                temp++;
                search=search+1;
            }

            ans=max(ans,temp);
        }


        return ans;
    }
};
