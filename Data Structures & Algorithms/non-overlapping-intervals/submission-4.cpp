class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();

        int a=intervals[0][0];
        int b=intervals[0][1];
        int ans=0;

        for(int i=1;i<n;i++){
                cout<<intervals[i][0]<<" "<<intervals[i][1]<<endl;
            
            if(intervals[i][0]>=b){
                a=intervals[i][0];
                b=intervals[i][1];
            }
            else{
                ans++;
                if(intervals[i][1]<b){
                    a=intervals[i][0];
                    b=intervals[i][1];
                }
            }

        }

        return ans;
    }
};
