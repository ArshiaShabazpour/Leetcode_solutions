#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();

        bool found = false;
        int minR = 0, minC = 0, maxR = 0, maxC = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    if (!found) {
                        found = true;
                        minR = maxR = i;
                        minC = maxC = j;
                    } else {
                        minR = min(minR, i);
                        minC = min(minC, j);
                        maxR = max(maxR, i);
                        maxC = max(maxC, j);
                    }
                }
            }
        }

        if (!found) return 0; 
        int height = maxR - minR + 1;
        int width  = maxC - minC + 1;
        return height * width;
    }
};
