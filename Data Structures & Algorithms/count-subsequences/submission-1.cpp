class Solution {
public:
    int solve(string &s,string &t,int i, int j){
        if(j==t.length()){
            return 1;            
        }
        if(i==s.length())return 0;


        int res = solve(s,t,i+1,j);
        if(s[i]==t[j]){
            return res+=solve(s,t,i+1,j+1);
        }
        
        return res;

    }
    int numDistinct(string s, string t) {
        
        return solve(s,t,0,0);
    }
};
