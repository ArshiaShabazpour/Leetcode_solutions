class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> perms;
        vector<int> perm;
        backtrack(nums, perm, perms);
        return perms;
    }

private:
    void backtrack(vector<int> nums, vector<int>& perm, vector<vector<int>>& perms) {
        if (nums.empty()) {
            perms.push_back(perm);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            vector<int> next_nums = nums;
            perm.push_back(nums[i]);
            next_nums.erase(next_nums.begin() + i);
            backtrack(next_nums, perm, perms);
            perm.pop_back();
        }
    }
};
