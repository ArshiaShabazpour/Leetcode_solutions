class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();
        int sum = 0;

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 1) {
                    int up   = matrix[i-1][j];
                    int left = matrix[i][j-1];
                    int diag = matrix[i-1][j-1];
                    if (up > 0 && left > 0 && diag > 0) {
                        matrix[i][j] = std::min({up, left, diag}) + 1; 
                    }
                }
                sum += matrix[i][j];
            }
        }

        for (int j = 0; j < n; ++j) if (matrix[0][j] == 1) ++sum;
        for (int i = 1; i < m; ++i) if (matrix[i][0] == 1) ++sum;

        return sum;
    }
};
