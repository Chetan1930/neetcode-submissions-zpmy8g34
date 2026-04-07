class Solution {
public:
    int maxArea(vector<int>& heights) {
        int max_area = 0;
        int left = 0;
        int right = heights.size() - 1;
        
        while (left < right) {
            int area = min(heights[left], heights[right]) * (right - left);
            max_area = max(max_area, area);
            
            if (heights[left] < heights[right]) {
                left += 1;
            } else {
                right -= 1;
            }
        }
        
        return max_area;
    }
};
