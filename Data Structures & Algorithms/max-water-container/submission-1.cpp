class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i=0;
        int j=heights.size()-1;
        int res=0;
        while(i<j){
            int temp=min(heights[i],heights[j]);
            res=max(res,temp*(j-i));

            if(heights[i]<=heights[j])i++;
            else j--;
        }

        return res;
    }
};
