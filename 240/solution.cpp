#include "../solution.h"
class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        int m = matrix.size();
        if(m == 0)
            return false;
        int n = matrix[0].size();
        return recursion(matrix, target, 0, m - 1 , 0, n - 1);
    }

    bool recursion(vector<vector<int> > &matrix, int target, int row1, int row2, int col1, int col2){
        if(row1 > row2 || col1 > col2)
            return false;
        else if(row2 - row1 + 1 <= 2 && col2 - col2 + 1 <= 2){
            for(int i=row1; i<=row2; i++){
                for(int j=col1; j<=col2; j++){
                    if(matrix[i][j] == target)
                        return true;
                }
            }
        }else{
            int row_mid = row1 + (row2 - row1) / 2;
            int col_mid = col1 + (col2 - col1) / 2;
            if(matrix[row_mid][col_mid] == target)
                return true;
            else if(matrix[row_mid][col_mid] > target){
                if(recursion(matrix, target, row1, row_mid - 1, col1, col2))
                    return true;
                else if(recursion(matrix, target, row_mid, row2, col1, col_mid -1))
                    return true;
            }else{
                if(recursion(matrix, target, row1, row_mid, col_mid + 1, col2))
                    return true;
                else if(recursion(matrix, target, row_mid + 1, row2, col1, col2))
                    return true;
            }
        }
        return false;
    }
};

