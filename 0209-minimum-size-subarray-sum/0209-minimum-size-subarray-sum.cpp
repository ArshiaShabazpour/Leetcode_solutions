class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int right = 0;
        int sum = 0;
        int size = 0; 
        int n = nums.size();

        for (int left = 0; left < n; ++left) {
            sum += nums[left];
            while (sum >= target) {
                int currLen = left - right + 1;
                if (size == 0 || currLen < size)
                    size = currLen;
                sum -= nums[right++];
            }
        }

        return size;
    }
};
