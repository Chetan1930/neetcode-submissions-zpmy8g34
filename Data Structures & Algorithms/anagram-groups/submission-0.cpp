class Solution {
public:

    int scoreOfStr(string &s){
        int score = 0;

        for(auto &i:s){
            score += i - '0';
        }

        return score;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        unordered_map<int,vector<string>>mp;

        for(auto &i:strs){
            int score=scoreOfStr(i);
            mp[score].push_back(i);  
        }

        for(auto i:mp){
            ans.push_back(i.second);
        }
        

        return ans;
    }
};
