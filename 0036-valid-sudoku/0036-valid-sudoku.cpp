class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9]  = {0};
        int cols[9]  = {0};
        int boxes[9] = {0};

        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                char ch = board[r][c];
                if (ch == '.') continue;

                int d = ch - '1';             
                int mask = 1 << d;             
                int b = (r/3)*3 + c/3;          

                if ((rows[r]  & mask) ||
                    (cols[c]  & mask) ||
                    (boxes[b] & mask)) {
                    return false;
                }

                rows[r]  |= mask;
                cols[c]  |= mask;
                boxes[b] |= mask;
            }
        }
        return true;
    }
};
