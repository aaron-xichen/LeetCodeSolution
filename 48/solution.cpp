#include "../solution.h"
class Solution {
public:
    void rotate(vector<vector<int> >& matrix) {
        int len = matrix.size();
        int iter = (len + 1) / 2;
        for(int i=0; i<iter; i++){
            int width = len - 2 * i - 1;
            for(int j=0; j<width; j++){
                // replace 4 element in clockwise order
                int tmp = matrix[i][i+j];
                matrix[i][i+j] = matrix[i+width-j][i];
                matrix[i+width-j][i] = matrix[i+width][i+width-j];
                matrix[i+width][i+width-j] = matrix[i+j][i+width];
                matrix[i+j][i+width] = tmp;
            }
        }
    }
};
