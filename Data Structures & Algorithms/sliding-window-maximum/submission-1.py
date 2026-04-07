from collections import deque
from typing import List

class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        if not nums:
            return []
        
        max_list = []
        window = deque()
        
        for i, num in enumerate(nums):
            # Remove elements from the back of the deque that are out of the window
            while window and window[0] < i - k + 1:
                window.popleft()
            
            # Remove elements from the front of the deque that are smaller than the current element
            while window and nums[window[-1]] < num:
                window.pop()
            
            window.append(i)
            
            # Add the maximum element in the window to the max_list
            if i >= k - 1:
                max_list.append(nums[window[0]])
        
        return max_list