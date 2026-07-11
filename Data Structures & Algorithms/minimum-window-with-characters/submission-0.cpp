class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() == 0 || t.size() == 0) return "";

        unordered_map<char, int> tCount;
        for (char c : t) {
            tCount[c]++;
        }

        int required = t.size();
        int formed = 0;
        unordered_map<char, int> windowCounts;
        int windowStart = 0;
        int minLen = INT_MAX;
        string minWindow = "";

        for (int windowEnd = 0; windowEnd < s.size(); windowEnd++) {
            char rightChar = s[windowEnd];
            windowCounts[rightChar]++;

            if (tCount.find(rightChar) != tCount.end() && windowCounts[rightChar] == tCount[rightChar]) {
                formed++;
            }

            while (windowStart <= windowEnd && formed == required) {
                char leftChar = s[windowStart];

                if (windowEnd - windowStart + 1 < minLen) {
                    minLen = windowEnd - windowStart + 1;
                    minWindow = s.substr(windowStart, minLen);
                }

                windowCounts[leftChar]--;
                if (tCount.find(leftChar) != tCount.end() && windowCounts[leftChar] < tCount[leftChar]) {
                    formed--;
                }

                windowStart++;
            }
        }

            return minWindow;
    }
};