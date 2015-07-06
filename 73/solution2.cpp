#include "../solution.h"
class Solution {
public:
    void setZeroes(vector<vector<int> >& matrix) {
        int row_num = matrix.size();
        int col_num = matrix[0].size();
        bool rows[row_num];
        bool cols[col_num];
        memset(rows, false, row_num*sizeof(rows[0]));
        memset(cols, false, col_num*sizeof(cols[0]));
        for(int i=0; i<row_num; i++){
            for(int j=0; j<col_num; j++){
                if(matrix[i][j] == 0){
                    rows[i] = true;
                    cols[j] = true;
                }
            }
        }

        for(int i=0; i<row_num; i++){
            for(int j=0; j<col_num; j++){
                if(rows[i] || cols[j])
                    matrix[i][j] = 0;
            }
        }
    }
};

