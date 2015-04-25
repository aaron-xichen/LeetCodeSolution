#include "../solution.h"
class Solution{
    public:
        vector<int> spiralOrder(vector<vector<int> >&matrix){
            int m = matrix.size();
            vector<int> traversal;
            if(0 == m) return traversal;
            int n = matrix[0].size();

            // trivial case
            if (1 == m){
                for(int j=0; j<n; j++)
                    traversal.push_back(matrix[0][j]);
                return traversal;
            }else if(1 == n){
                for(int i=0; i<m; i++)
                    traversal.push_back(matrix[i][0]);
                return traversal;
            }
            int row=0, col=0;
            // 0 represents right
            // 1 represents down
            // 2 represents left
            // 3 represents up
            int direction = 0;
            // move towards right
            for(int j=0; j<n; j++){
                traversal.push_back(matrix[row][col++]);
            }
            col--;
            row++;
            direction = (direction + 1) % 4;

            int r = 1;
            int total = n;
            while(true){
                if(direction == 0){
                    for(int i=0; i<m-r; i++){
                        traversal.push_back(matrix[row][col++]);
                    }
                    col--;
                    row++;
                }else if(direction == 1){
                    for(int i=0; i<m-r; i++){
                        traversal.push_back(matrix[row++][col]);
                    }
                    row--;
                    col--;
                }else if(direction == 2){
                    for(int i=0; i<m-r; i++){
                        traversal.push_back(matrix[row][col--]);
                    }
                    col++;
                    row--;
                }else if(direction == 3){
                    for(int i=0; i<m-r; i++){
                        traversal.push_back(matrix[row--][col]);
                    }
                    row++;
                    col++;
                }
                total += m-r;
                direction = (direction + 1) % 4;
                if(total == m*n) break;

                if(direction == 0){
                    for(int i=0; i<n-r; i++){
                        traversal.push_back(matrix[row][col++]);
                    }
                    col--;
                    row++;
                }else if(direction == 1){
                    for(int i=0; i<n-r; i++){
                        traversal.push_back(matrix[row++][col]);
                    }
                    row--;
                    col--;
                }else if(direction == 2){
                    for(int i=0; i<n-r; i++){
                        traversal.push_back(matrix[row][col--]);
                    }
                    col++;
                    row--;
                }else if(direction == 3){
                    for(int i=0; i<n-r; i++){
                        traversal.push_back(matrix[row--][col]);
                    }
                    row++;
                    col++;
                }
                total += n-r;
                direction = (direction + 1) % 4;
                if(total == m*n) break;
                r++;
            }
            return traversal;
        }
};
