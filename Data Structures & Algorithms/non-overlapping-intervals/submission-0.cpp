class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        int n=intervals.size();

        int a=intervals[0][0];
        int b=intervals[0][1];
        sort(intervals.begin(),intervals.end());
        int ans=0;

        for(int i=1;i<n;i++){
            
            if(intervals[i][0]<b){
                ans++;
            }
            else{
                a=intervals[i][0];
                b=intervals[i][1];
            }

        }

        return ans;
    }
};
