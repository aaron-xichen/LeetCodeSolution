#include "../solution.h"
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> result;
        if (matrix.empty()) return result;
        result = matrix[0];  // no need to check the first row
        int dirs[4][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};  // direction offsets
        int d = 0;  // direction index
        int m = matrix.size();
        int n = matrix[0].size();
        int pos[2] = {0, n - 1};  // start from the top right corner
        int i = (m - 1) * n;  // number of the rest numbers
        while (i > 0) {
            for (int j = 1; j < m; j++) {
                i--;
                pos[0] += dirs[d][0]; pos[1] += dirs[d][1];
                result.push_back(matrix[pos[0]][pos[1]]);
            }
            m--;  // decrease the size of row or column
            swap(m, n);  // switch between horizontal and vertical mode
            d = (d + 1) % 4;  // loop between direction offsets
        }
        return result;
    }
};
