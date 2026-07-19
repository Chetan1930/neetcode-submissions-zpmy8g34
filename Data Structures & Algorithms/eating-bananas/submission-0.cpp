class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long left = 1;
        long right = *max_element(piles.begin(), piles.end()) + 1;
        
        while (left + 1 < right) {
            long mid = left + (right - left) / 2;
            long hours = 0;
            for (int pile : piles) {
                hours += (pile + mid - 1) / mid;
            }
            if (hours > h) {
                left = mid;
            } else {
                right = mid;
            }
        }
        
        return right;
    }
};