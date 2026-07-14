class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> res;
        
        for (int i = 0; i < nums.size(); i++) {
            // Remove elements from the back of the deque that are smaller than the current element
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            
            // Remove elements from the front of the deque that are out of the current window
            while (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }
            
            // Add the index of the current element to the back of the deque
            dq.push_back(i);
            
            // Add the maximum element in the window to the result
            if (i >= k - 1) {
                res.push_back(nums[dq.front()]);
            }
        }
        
        return res;
    }
};
