class Solution {
public:
    vector<pair<int, int>> movs = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        int total_rows = grid.size();
        int total_cols = grid[0].size();
        for(int row=0; row<total_rows; row++){
            for(int col=0; col<total_cols; col++){
                if (grid[row][col] == '1'){
                    dfs(grid, row, col, total_rows, total_cols);
                    islands++;
                }
            }
        }
        return islands;
    }

private:

    void dfs(vector<vector<char>>& grid, int row, int col, int total_rows, int total_cols){
        if (grid[row][col] != '1'){
            return;
        }
        grid[row][col] = '0';
        for(pair<int, int> mov:movs){
            int next_row = row + mov.first;
            int next_col = col + mov.second;
            if (is_inside_bounds(next_row, next_col, total_rows, total_cols)) {
                dfs(grid, next_row, next_col, total_rows, total_cols);
            }
        }

    }

    bool is_inside_bounds(int row, int col, int total_rows, int total_cols){
        return (row>=0 && row<total_rows && col>=0 && col<total_cols);
    }
    
};