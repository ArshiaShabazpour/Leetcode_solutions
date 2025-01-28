class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0; 
        int size = nums.size();
        
        for (int i = 0; i < size; ++i) {
            if (i > maxReach) {
                return false; 
            }
            maxReach = max(maxReach, i + nums[i]);
            if (maxReach >= size - 1) {
                return true; 
            }
        }
        
        return false; 
    }
};
