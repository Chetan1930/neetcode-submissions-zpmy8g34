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
    bool canAttendMeetings(vector<Interval>& v) {
        
        int n=v.size();
        if(n==0)return true;
        vector<vector<int>>intervals;
        for(auto &i:v){
            intervals.push_back({i.start,i.end});
        }
        sort(intervals.begin(),intervals.end());

        int a=intervals[0][0];
        int b=intervals[0][1];

        for(int i=1;i<n;i++){
            if(intervals[i][0] < b)return false;
            else {
                a=intervals[i][0];
                b=intervals[i][1];
            }
        }
        return true;
    }
};
