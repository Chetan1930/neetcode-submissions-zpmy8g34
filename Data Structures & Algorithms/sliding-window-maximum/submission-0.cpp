class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> result;
        
        for (int i = 0; i < nums.size(); i++) {
            // Remove elements from the back of the deque that are out of the current window
            while (!dq.empty() && dq.front() < i - k + 1) {
                dq.pop_front();
            }
            
            // Remove elements from the back of the deque that are smaller than the current element
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            
            // Add the current element to the back of the deque
            dq.push_back(i);
            
            // Add the maximum element of the deque to the result
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }
        
        return result;
    }
};