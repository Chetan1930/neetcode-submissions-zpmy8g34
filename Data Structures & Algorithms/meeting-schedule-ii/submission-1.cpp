/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& v) {
        int ans=0;
        unordered_map<int,int>s,e;
        int start =0, end =0;


        for(int i=0;i<v.size();i++){
            start=min(start,v[i].start);
            end = max(end,v[i].end);
            s[v[i].start]++;
            e[v[i].end]++;
        }

        
        int temp = 0;
        for(int j=start;j<=end;j++){
            temp += s[j];
            temp -= e[j];

            ans = max(temp,ans);
        }


        return ans;


    }
};
