class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n = s.length();
        if (n <= 1) return n;

        int l = 0, r = 0;
        unordered_map<char,int> mp;
        int maxlen = 0;

        while (r < n) {

            mp[s[r]]++;

            while (mp[s[r]] > 1) {
                mp[s[l]]--;
                if (mp[s[l]] == 0)
                    mp.erase(s[l]);
                l++;
            }

            maxlen = max(maxlen, r - l + 1);

            r++;
        }

        return maxlen;
    }
};