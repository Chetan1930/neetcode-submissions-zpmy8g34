class Solution {
public:
     unordered_map<string,int>mp;

    int solve(string &s,string &t,int i, int j){
        if(j==t.length()){
            return 1;            
        }
        if(i==s.length())return 0;
        string temp = to_string(i) + "-" + to_string(j);

        if(mp.count(temp))return mp[temp];

        int res = solve(s,t,i+1,j);
        if(s[i]==t[j]){
            return  res+=solve(s,t,i+1,j+1);
        }
        
        return mp[temp] = res;

    }
    int numDistinct(string s, string t) {
        
        return solve(s,t,0,0);
    }
};
