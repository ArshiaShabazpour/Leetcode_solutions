class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int last_one_index = -k - 1; 

        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                int distance = i - last_one_index - 1;
                
                if (distance < k) {
                    return false;
                }
                
                last_one_index = i;
            }
        }
        
        return true; 
    }
};