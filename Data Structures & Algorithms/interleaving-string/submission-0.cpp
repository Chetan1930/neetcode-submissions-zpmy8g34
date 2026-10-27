class Solution {
public:
    unordered_map<string,bool>mp;


    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size(), l = s3.size();

        if (n + m != l) return false;

        return solve(s1, s2, s3, 0, 0, 0);
    }

    bool solve(string& s1, string& s2, string& s3,
               int i, int j, int k) {

        if (k == s3.size())
            return i == s1.size() && j == s2.size();
        string temp = to_string(i);
        temp+="-";
        temp+=to_string(j);

        if(mp.count(temp))return mp[temp];


        bool result1 = false, result2 = false;

        if (i < s1.size() && s1[i] == s3[k])
            result1 = solve(s1, s2, s3, i+1, j, k+1);

        if (j < s2.size() && s2[j] == s3[k])
            result2 = solve(s1, s2, s3, i, j+1, k+1);

        return mp[temp] = result1 || result2;
    }
};