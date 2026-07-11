class Solution {
public:

    bool charmatch(string &s,unordered_map<char,int>mp){

        for(auto &i:s){
            if(mp[i]==0)return false;
            mp[i]--;
        }

        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int n=s1.length();
        if(n>s2.length())return false;
        unordered_map<char,int>mp;
        for(auto &i:s1)mp[i]++;


        for(int i=0;i<=s2.length()-n;i++){
            string temp = s2.substr(i,n);
            if(charmatch(temp,mp))return true;
        }
        
        return false;

    }
};
