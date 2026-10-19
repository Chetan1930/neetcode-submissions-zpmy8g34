class Solution {
public:
    int solve(string &s,int i){
        if(i==s.length())return 1;
        if(s[i]=='0')return 0;

        int res =  solve(s,i+1);

        if (i < s.size() - 1) {
            if (s[i] == '1' ||
               (s[i] == '2' && s[i + 1] < '7')) {
                res += solve(s,i + 2);
            }
        }

        return res;

    }
    int numDecodings(string s) {
        
        int ans = solve(s,0);

        return ans;
    }
};
