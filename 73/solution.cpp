#include "../solution.h"
class Solution {
public:
    void setZeroes(vector<vector<int> >& matrix) {
        int row_num = matrix.size();
        int col_num = matrix[0].size();
        recusion(matrix, 0, 0, row_num-1, col_num-1);
    }

    void recusion(vector<vector<int> >& matrix, int left_up_row, int left_up_col, int right_down_row, int right_down_col){
        for(int i=left_up_row; i<=right_down_row; i++){
            for(int j=left_up_col; j<=right_down_col; j++){
                if(matrix[i][j] == 0){
                    int row_num = matrix.size();
                    int col_num = matrix[0].size();
                    for(int k=0; k<col_num; k++){
                        matrix[i][k] = 0;
                    }
                    for(int k=0; k<row_num; k++){
                        matrix[k][j] = 0;
                    }
                    recusion(matrix, i+1, left_up_col, right_down_row, j-1);
                    recusion(matrix, i+1, j+1, right_down_row, right_down_col);
                    return;
                }
            }
        }
    }
};

