#include "../solution.h"
class Solution{
    public:
        vector<vector<int> > generateMatrix(int n){
            vector<vector<int> > matrix;
            // trivial case
            if(n < 1)
                return matrix;
            else if(n == 1){
                vector<int> row;
                row.push_back(1);
                matrix.push_back(row);
                return matrix;
            }

            // initialization
            vector<int> base;
            for(int i=0; i<n; i++)
                base.push_back(i+1);
            for(int i=0; i<n;i++)
                matrix.push_back(base);

            // begin from right-up corner
            int row_num = n-1;
            int col_num = n-1;
            int counter = n;
            int row = 0;
            int col = n-1;
            int direction = 1;
            int ops[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
            while(counter < n*n){
                for(int i=0; i<row_num; i++){
                    row += ops[direction][0];
                    col += ops[direction][1];
                    counter ++;
                    matrix[row][col] = counter;
                }
                row_num--;
                swap(row_num, col_num);
                direction = (direction + 1) % 4;
            }
            return matrix;
        }
};
