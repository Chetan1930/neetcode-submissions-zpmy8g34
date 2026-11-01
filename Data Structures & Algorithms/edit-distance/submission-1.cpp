class Solution {
public:
    unordered_map<string,int>mp;

    int solve(int i, int j, string &w1, string &w2, int n, int m ){
        if(i==n)return m-j;
        if(j==m)return n-i;
        string temp = to_string(i) +"-" + to_string(j);

        if(mp.count(temp))return mp[temp];


        if(w1[i]==w2[j])return solve(i+1,j+1,w1,w2,n,m);

        return mp[temp] = 1+  min({solve(i+1,j,w1,w2,n,m),solve(i,j+1,w1,w2,n,m),solve(i+1,j+1,w1,w2,n,m)});
    }
    int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();

        return solve(0,0,word1,word2,n,m);
    }
};
