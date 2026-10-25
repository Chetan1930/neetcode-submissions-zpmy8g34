class Solution {
public:
    int solve(string&s1,string &s2,int n,int m,int i, int j){
        if(i>=n || j>=m)return 0;

        if(s1[i]==s2[j]){
            return 1+ solve(s1,s2,n,m,i+1,j+1);
        }

        else return max(solve(s1,s2,n,m,i+1,j),solve(s1,s2,n,m,i,j+1));
    }
    int longestCommonSubsequence(string text1, string text2) {
        
        int n=text1.length();
        int m = text2.length();

        return solve(text1,text2,n,m,0,0);
    }
};
