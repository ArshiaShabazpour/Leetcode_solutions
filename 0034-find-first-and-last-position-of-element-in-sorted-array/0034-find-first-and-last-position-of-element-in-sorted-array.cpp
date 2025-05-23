class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> pos{-1, -1};
        int n = nums.size();
        if (n == 0) return pos;

        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                pos[0] = pos[1] = mid;
                int i = mid - 1;
                while (i >= 0 && nums[i] == target) {
                    pos[0] = i;
                    --i;
                }
                i = mid + 1;
                while (i < n && nums[i] == target) {
                    pos[1] = i;
                    ++i;
                }
                break;  
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return pos;
    }
};
