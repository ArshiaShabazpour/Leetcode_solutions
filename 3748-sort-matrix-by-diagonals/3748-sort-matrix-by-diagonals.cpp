class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        if (grid.size() < 2) return grid;
        int n = grid.size();
        vector<int> nums;
        for (int i = 0, j = n - 2; j >= 1; j--) {
            while (j < n)
                nums.push_back(grid[i++][j++]);
            sort(nums.begin(), nums.end());
            for (auto it = nums.rbegin(); it != nums.rend(); it++)
                grid[--i][--j] = *it;
            nums.clear();
        }
        for (int i = 0, j = 0; i <= n - 2; i++) {
            while (i < n)
                nums.push_back(grid[i++][j++]);
            sort(nums.begin(), nums.end());
            for (int n : nums)
                grid[--i][--j] = n;
            nums.clear();
        }
        return grid;
    }
};