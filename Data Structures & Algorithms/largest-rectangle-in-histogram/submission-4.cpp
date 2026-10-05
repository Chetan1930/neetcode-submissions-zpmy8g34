class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> stack;
        int max_area = 0;

        for (int i = 0; i <= n; i++) {
            int height = (i == n) ? 0 : heights[i];
            while (!stack.empty() && heights[stack.back()] >= height) {
                int top = stack.back();
                stack.pop_back();
                int width = stack.empty() ? i : i - stack.back() - 1;
                max_area = max(max_area, heights[top] * width);
            }
            stack.push_back(i);
        }
        return max_area;
    }
};