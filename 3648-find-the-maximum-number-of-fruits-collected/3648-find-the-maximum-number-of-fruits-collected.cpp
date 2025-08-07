class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& grid) {
        int n = grid.size(), res = 0;
        for (int i = 0; i < n; i++) res += grid[i][i];

        auto get = [&](int r, int c, int pass) -> int {
            return (pass == 0) ? grid[r][c] : grid[c][r];
        };

        for (int pass = 0; pass < 2; pass++) {
            vector<int> prev(n, -1), curr(n, -1);
            prev[n - 1] = get(0, n - 1, pass);

            for (int row = 1; row < n - 1; row++) {
                fill(curr.begin(), curr.end(), -1);
                for (int i = 0; i < n; i++) {
                    if (prev[i] < 0) continue;
                    if (i > 0)
                        curr[i - 1] = max(curr[i - 1], prev[i] + get(row, i - 1, pass));
                    if (i < n - 1)
                        curr[i + 1] = max(curr[i + 1], prev[i] + get(row, i + 1, pass));
                    curr[i] = max(curr[i], prev[i] + get(row, i, pass));
                }
                swap(prev, curr);
            }
            res += prev[n - 1];
        }
        return res;
    }
};
