class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();

        int a=intervals[0][0];
        int b=intervals[0][1];
        int ans=0;

        for(int i=1;i<n;i++){
            
            if(intervals[i][0]<b){
                ans++;
                // cout<<a<<" "<<b<<endl;
            }
            else{
                a=intervals[i][0];
                b=intervals[i][1];
            }

        }

        return ans;
    }
};
