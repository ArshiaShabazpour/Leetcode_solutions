class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = 0;          
        int zero_index = -1;  
        int best = 0;

        for (int right = 0; right < n; ++right) {
            if (nums[right] == 0) {
                if (zero_index < 0) {
                    zero_index = right;
                } else {
                    left = zero_index + 1;
                    zero_index = right; 
                }
            }
            best = max(best, right - left);
        }
        return best;
    }
};
