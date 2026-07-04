class Solution {
public:

    string scoreOfStr(string &s){
        string score = s;
        sort(score.begin(), score.end());

        return score;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        unordered_map<string,vector<string>>mp;


        for(auto &i:strs){
            string score=scoreOfStr(i);
            mp[score].push_back(i);  
        }

        for(auto i:mp){
            ans.push_back(i.second);
        }
        

        return ans;
    }
};
