class Solution {
    /**
     * @param {number[]} heights
     * @return {number}
     */
    largestRectangleArea(heights) {
    let stack = [];
    let maxArea = 0;

    for (let i = 0; i < heights.length; i++) {
        while (stack.length && heights[stack[stack.length - 1]] >= heights[i]) {
            let height = heights[stack.pop()];
            let width = stack.length == 0 ? i : i - stack[stack.length - 1] - 1;
            maxArea = Math.max(maxArea, height * width);
        }
        stack.push(i);
    }

    while (stack.length) {
        let height = heights[stack.pop()];
        let width = stack.length == 0 ? heights.length : heights.length - stack[stack.length - 1] - 1;
        maxArea = Math.max(maxArea, height * width);
    }

    return maxArea;
}
}
