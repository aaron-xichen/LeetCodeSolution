#include "../solution.h"
class Solution {
public:
    int minPathSum(vector<vector<int> >& grid) {
        for(int i=0; i<(int)grid.size(); i++){
            for(int j=0; j<(int)grid[i].size(); j++){
                if(i-1 >= 0 && j-1 >= 0)
                    grid[i][j] = min(grid[i][j-1], grid[i-1][j]) + grid[i][j];
                else if(i-1 >= 0)
                    grid[i][j] = grid[i-1][j] + grid[i][j];
                else if(j-1 >= 0)
                    grid[i][j] = grid[i][j-1] + grid[i][j];
            }
        }
        return grid[grid.size()-1][grid[grid.size()-1].size()-1];
    }
};
