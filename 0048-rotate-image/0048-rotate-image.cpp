class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i = 0; i <matrix.size()-1; i++){
            for(int j = 1+i; j<matrix.size();j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp; 
            }
        }
        for(int i = 0; i <matrix.size(); i++){
            int right =0;
            int left = matrix[i].size()-1;
            while(right<left){
                int temp = matrix[i][right];
                matrix[i][right] = matrix[i][left];
                matrix[i][left] = temp;
                right++;
                left--;
            }
        }
        
    }
};